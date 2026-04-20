#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasemanager.h"

#include "artistsdialog.h"
#include "venuesdialog.h"
#include "categoriesdialog.h"
#include "showsdialog.h"
#include "worklogdialog.h"

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTableView>
#include <QDebug>
#include <QSqlError>
#include <QSqlField>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(LoginDialog::Role role, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_userRole(role)
{
    ui->setupUi(this);
    setupTableModels();

    // Создаём вкладки
    QStringList tables = {"venues", "categories", "artists", "shows", "work_log"};
    for (const QString &t : tables) {
        ui->tabWidget->addTab(createTableTab(t), t);
    }

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTableSelectionChanged);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::on_actionAbout_triggered);
    connect(ui->actionGuide, &QAction::triggered, this, &MainWindow::on_actionGuide_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTableModels()
{
    QStringList tables = {"venues", "categories", "artists", "shows", "work_log"};
    for (const QString &t : tables) {
        QSqlTableModel *model = new QSqlTableModel(this, DatabaseManager::database());
        model->setTable(t);
        if (t == "Artists") {
            model->setHeaderData(1, Qt::Horizontal, "ФИО");
            model->setHeaderData(2, Qt::Horizontal, "Категория");
            model->setHeaderData(3, Qt::Horizontal, "Описание");
            model->setHeaderData(4, Qt::Horizontal, "Рейтинг");
            model->setHeaderData(5, Qt::Horizontal, "Путь к фото");
        }
        // аналогично задать заголовки для остальных таблиц
        model->setEditStrategy(m_userRole == LoginDialog::Guest ?
                                   QSqlTableModel::OnManualSubmit :
                                   QSqlTableModel::OnFieldChange);
        model->select();

        // В методе setupTableModels() для каждой таблицы создаётся прокси-модель
        QSortFilterProxyModel *proxy = new QSortFilterProxyModel(this);
        proxy->setSourceModel(model);                           // связываем с моделью данных
        proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);  // поиск без учёта регистра
        proxy->setFilterKeyColumn(-1);                        // поиск по всем колонкам

        m_models[t] = model;
        m_proxies[t] = proxy;
    }
}

QWidget* MainWindow::createTableTab(const QString &tableName)
{
    QWidget *tab = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(tab);

    // Панель управления
    QHBoxLayout *toolbar = new QHBoxLayout;
    QPushButton *btnAdd = new QPushButton("Добавить");
    QPushButton *btnEdit = new QPushButton("Редактировать");
    QPushButton *btnDelete = new QPushButton("Удалить");

    // В createTableTab() создаётся поле ввода и подключается к слоту фильтрации
    QLineEdit *searchEdit = new QLineEdit;
    searchEdit->setPlaceholderText("Поиск...");

    if (m_userRole == LoginDialog::Guest) {
        btnAdd->setEnabled(false);
        btnEdit->setEnabled(false);
        btnDelete->setEnabled(false);
    }

    toolbar->addWidget(btnAdd);
    toolbar->addWidget(btnEdit);
    toolbar->addWidget(btnDelete);
    toolbar->addStretch();
    toolbar->addWidget(new QLabel("Поиск:"));
    toolbar->addWidget(searchEdit);

    // Таблица
    QTableView *view = new QTableView;
    view->setModel(m_proxies[tableName]);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSortingEnabled(true);
    view->horizontalHeader()->setStretchLastSection(true);
    view->verticalHeader()->setVisible(false);
    // Скрываем первичный ключ (колонка 0)
    view->setColumnHidden(0, true);

    // Для Artists дополнительно можно настроить делегат для отображения фото (опционально)
    if (tableName == "Artists") {
        // Здесь можно установить делегат для колонки с путём или создать отдельную колонку с превью
    }

    layout->addLayout(toolbar);
    layout->addWidget(view);

    m_views[tableName] = view;

    // Подключение сигналов
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::addRecord);
    connect(btnEdit, &QPushButton::clicked, this, &MainWindow::editRecord);
    connect(btnDelete, &QPushButton::clicked, this, &MainWindow::deleteRecord);
    connect(searchEdit, &QLineEdit::textChanged, this, &MainWindow::searchTextChanged);

    return tab;
}

void MainWindow::addRecord()
{
    QString currentTable = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    QString tableLower = currentTable.toLower();

    if (tableLower == "artists") {
        ArtistsDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QSqlTableModel *model = m_models["artists"];
            // Вставляем пустую строку в конец
            int row = model->rowCount();
            if (!model->insertRow(row)) {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить строку: " + model->lastError().text());
                return;
            }

            // Получаем данные из диалога
            QSqlRecord rec = dialog.getData();

            // Заполняем поля модели
            model->setData(model->index(row, model->fieldIndex("artist_fullname")),
                           rec.value("artist_fullname"));
            model->setData(model->index(row, model->fieldIndex("category_id")),
                           rec.value("category_id"));
            model->setData(model->index(row, model->fieldIndex("artist_description")),
                           rec.value("artist_description"));
            model->setData(model->index(row, model->fieldIndex("artist_rating")),
                           rec.value("artist_rating"));
            model->setData(model->index(row, model->fieldIndex("artist_photo_path")),
                           rec.value("artist_photo_path"));

            // Сохраняем в базу данных
            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить запись: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select(); // обновляем представление
            }
        }
    }
    else if (tableLower == "venues") {
        VenuesDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QSqlTableModel *model = m_models["venues"];
            int row = model->rowCount();
            if (!model->insertRow(row)) {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить строку: " + model->lastError().text());
                return;
            }
            QSqlRecord rec = dialog.getData();
            model->setData(model->index(row, model->fieldIndex("venue_name")), rec.value("venue_name"));
            model->setData(model->index(row, model->fieldIndex("venue_base_price")), rec.value("venue_base_price"));
            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить запись: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "categories") {
        CategoriesDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QSqlTableModel *model = m_models["categories"];
            int row = model->rowCount();
            if (!model->insertRow(row)) {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить строку: " + model->lastError().text());
                return;
            }
            QSqlRecord rec = dialog.getData();
            model->setData(model->index(row, model->fieldIndex("category_name")), rec.value("category_name"));
            model->setData(model->index(row, model->fieldIndex("category_genre")), rec.value("category_genre"));
            model->setData(model->index(row, model->fieldIndex("category_artists")), rec.value("category_artists"));
            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить запись: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "shows") {
        ShowsDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QSqlTableModel *model = m_models["shows"];
            int row = model->rowCount();
            if (!model->insertRow(row)) {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить строку: " + model->lastError().text());
                return;
            }
            QSqlRecord rec = dialog.getData();
            model->setData(model->index(row, model->fieldIndex("show_name")), rec.value("show_name"));
            model->setData(model->index(row, model->fieldIndex("venue_id")), rec.value("venue_id"));
            model->setData(model->index(row, model->fieldIndex("show_date")), rec.value("show_date"));
            model->setData(model->index(row, model->fieldIndex("show_ticket_price")), rec.value("show_ticket_price"));
            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить запись: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "work_log") {
        WorkLogDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QSqlTableModel *model = m_models["work_log"];
            int row = model->rowCount();
            if (!model->insertRow(row)) {
                QMessageBox::critical(this, "Ошибка", "Не удалось добавить строку: " + model->lastError().text());
                return;
            }
            QSqlRecord rec = dialog.getData();
            model->setData(model->index(row, model->fieldIndex("artist_id")), rec.value("artist_id"));
            model->setData(model->index(row, model->fieldIndex("show_id")), rec.value("show_id"));
            model->setData(model->index(row, model->fieldIndex("log_payday")), rec.value("log_payday"));
            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить запись: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
}

void MainWindow::editRecord()
{
    QString currentTable = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    QString tableLower = currentTable.toLower();
    QTableView *view = m_views[currentTable];
    QModelIndex proxyIndex = view->currentIndex();

    if (!proxyIndex.isValid()) {
        QMessageBox::information(this, "Информация", "Выберите запись для редактирования");
        return;
    }

    QModelIndex sourceIndex = m_proxies[currentTable]->mapToSource(proxyIndex);
    int row = sourceIndex.row();

    if (tableLower == "artists") {
        QSqlTableModel *model = m_models["artists"];
        QSqlRecord rec = model->record(row);

        ArtistsDialog dialog(this);
        dialog.setData(rec);

        if (dialog.exec() == QDialog::Accepted) {
            QSqlRecord newData = dialog.getData();

            model->setData(model->index(row, model->fieldIndex("artist_fullname")),
                           newData.value("artist_fullname"));
            model->setData(model->index(row, model->fieldIndex("category_id")),
                           newData.value("category_id"));
            model->setData(model->index(row, model->fieldIndex("artist_description")),
                           newData.value("artist_description"));
            model->setData(model->index(row, model->fieldIndex("artist_rating")),
                           newData.value("artist_rating"));
            model->setData(model->index(row, model->fieldIndex("artist_photo_path")),
                           newData.value("artist_photo_path"));

            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить изменения: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "venues") {
        QSqlTableModel *model = m_models["venues"];
        QSqlRecord rec = model->record(row);

        VenuesDialog dialog(this);
        dialog.setData(rec);

        if (dialog.exec() == QDialog::Accepted) {
            QSqlRecord newData = dialog.getData();

            model->setData(model->index(row, model->fieldIndex("venue_name")),
                           newData.value("venue_name"));
            model->setData(model->index(row, model->fieldIndex("venue_base_price")),
                           newData.value("venue_base_price"));

            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить изменения: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "categories") {
        QSqlTableModel *model = m_models["categories"];
        QSqlRecord rec = model->record(row);

        CategoriesDialog dialog(this);
        dialog.setData(rec);

        if (dialog.exec() == QDialog::Accepted) {
            QSqlRecord newData = dialog.getData();

            model->setData(model->index(row, model->fieldIndex("category_name")),
                           newData.value("category_name"));
            model->setData(model->index(row, model->fieldIndex("category_genre")),
                           newData.value("category_genre"));
            model->setData(model->index(row, model->fieldIndex("category_artists")),
                           newData.value("category_artists"));

            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить изменения: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "shows") {
        QSqlTableModel *model = m_models["shows"];
        QSqlRecord rec = model->record(row);

        ShowsDialog dialog(this);
        dialog.setData(rec);

        if (dialog.exec() == QDialog::Accepted) {
            QSqlRecord newData = dialog.getData();

            model->setData(model->index(row, model->fieldIndex("show_name")),
                           newData.value("show_name"));
            model->setData(model->index(row, model->fieldIndex("venue_id")),
                           newData.value("venue_id"));
            model->setData(model->index(row, model->fieldIndex("show_date")),
                           newData.value("show_date"));
            model->setData(model->index(row, model->fieldIndex("show_ticket_price")),
                           newData.value("show_ticket_price"));

            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить изменения: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }
    else if (tableLower == "work_log") {
        QSqlTableModel *model = m_models["work_log"];
        QSqlRecord rec = model->record(row);

        WorkLogDialog dialog(this);
        dialog.setData(rec);

        if (dialog.exec() == QDialog::Accepted) {
            QSqlRecord newData = dialog.getData();

            model->setData(model->index(row, model->fieldIndex("artist_id")),
                           newData.value("artist_id"));
            model->setData(model->index(row, model->fieldIndex("show_id")),
                           newData.value("show_id"));
            model->setData(model->index(row, model->fieldIndex("log_payday")),
                           newData.value("log_payday"));

            if (!model->submitAll()) {
                QMessageBox::critical(this, "Ошибка", "Не удалось сохранить изменения: " + model->lastError().text());
                model->revertAll();
            } else {
                model->select();
            }
        }
    }

}

void MainWindow::deleteRecord()
{
    if (m_userRole == LoginDialog::Guest) return;
    QString currentTable = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    QTableView *view = m_views[currentTable];
    QModelIndex proxyIndex = view->currentIndex();
    if (!proxyIndex.isValid()) return;

    int ret = QMessageBox::question(this, "Подтверждение", "Удалить выбранную запись?");
    if (ret == QMessageBox::Yes) {
        QModelIndex sourceIndex = m_proxies[currentTable]->mapToSource(proxyIndex);
        m_models[currentTable]->removeRow(sourceIndex.row());
        m_models[currentTable]->submitAll();
    }
}

// Слот, вызываемый при изменении текста поиска
void MainWindow::searchTextChanged(const QString &text)
{
    QString currentTable = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    m_proxies[currentTable]->setFilterFixedString(text);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе",
                       "Практическое приложение для работы с БД\n"
                       "Версия 1.0\n"
                       "Разработано в учебных целях\n"
                       "Студентом ИСПП 23 1/9\n"
                       "Полищук Никита Артемович.");
}

void MainWindow::on_actionGuide_triggered()
{
    QString guide =
        "1. Выберите вкладку с нужной таблицей.\n"
        "2. Для добавления записи нажмите «Добавить».\n"
        "3. Для редактирования выберите строку и нажмите «Редактировать».\n"
        "4. Для удаления выберите строку и нажмите «Удалить».\n"
        "5. Поиск осуществляется по всем колонкам.\n"
        "6. Гость может только просматривать данные.";
    QMessageBox::information(this, "Руководство пользователя", guide);
}

void MainWindow::onTableSelectionChanged(int index)
{
    // Опционально: обновить заголовок или состояние кнопок
}
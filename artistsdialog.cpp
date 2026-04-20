#include "artistsdialog.h"
#include "ui_artistsdialog.h"
#include "databasemanager.h"
#include <QSqlField>
#include <QSqlRecord>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QSqlQuery>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>

ArtistsDialog::ArtistsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArtistsDialog),
    m_artistId(-1)
{
    ui->setupUi(this);
    loadCategories();
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

ArtistsDialog::~ArtistsDialog()
{
    delete ui;
}

void ArtistsDialog::loadCategories()
{
    QSqlQuery query("SELECT category_id, category_name FROM Categories ORDER BY category_name");
    while (query.next()) {
        ui->comboCategory->addItem(query.value(1).toString(), query.value(0));
    }
}

void ArtistsDialog::setData(const QSqlRecord &record)
{
    m_artistId = record.value("artist_id").toInt();
    ui->lineEditFullname->setText(record.value("artist_fullname").toString());
    int catId = record.value("category_id").toInt();
    int idx = ui->comboCategory->findData(catId);
    if (idx >= 0) ui->comboCategory->setCurrentIndex(idx);
    ui->textEditDescription->setPlainText(record.value("artist_description").toString());
    ui->doubleSpinBoxRating->setValue(record.value("artist_rating").toDouble());
    ui->lineEditPhotoPath->setText(record.value("artist_photo_path").toString());
}

QSqlRecord ArtistsDialog::getData() const
{
    QSqlRecord rec;
    QSqlField fldId("artist_id", QVariant::Int);
    if (m_artistId != -1) fldId.setValue(m_artistId);
    rec.append(fldId);
    rec.append(QSqlField("artist_fullname", QVariant::String));
    rec.append(QSqlField("category_id", QVariant::Int));
    rec.append(QSqlField("artist_description", QVariant::String));
    rec.append(QSqlField("artist_rating", QVariant::Double));
    rec.append(QSqlField("artist_photo_path", QVariant::String));

    rec.setValue("artist_fullname", ui->lineEditFullname->text().trimmed());
    rec.setValue("category_id", ui->comboCategory->currentData().toInt());
    rec.setValue("artist_description", ui->textEditDescription->toPlainText());
    rec.setValue("artist_rating", ui->doubleSpinBoxRating->value());
    rec.setValue("artist_photo_path", ui->lineEditPhotoPath->text());

    return rec;
}

void ArtistsDialog::on_btnBrowsePhoto_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите фотографию",
                                                    QString(),
                                                    "Изображения (*.png *.jpg *.jpeg *.bmp)");
    if (!fileName.isEmpty()) {
        ui->lineEditPhotoPath->setText(fileName);
    }
}

void ArtistsDialog::on_btnViewPhoto_clicked()
{
    QString path = ui->lineEditPhotoPath->text();
    if (path.isEmpty()) {
        QMessageBox::information(this, "Просмотр", "Фотография не выбрана.");
        return;
    }
    QPixmap pix(path);
    if (pix.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение.");
        return;
    }
    QLabel *label = new QLabel;
    label->setPixmap(pix.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label->setWindowTitle("Просмотр фотографии");
    label->setAttribute(Qt::WA_DeleteOnClose);
    label->show();
}

void ArtistsDialog::accept()
{
    if (ui->lineEditFullname->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите ФИО артиста");
        return;
    }
    if (ui->comboCategory->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите категорию");
        return;
    }
    QDialog::accept();
}
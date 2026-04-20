#include "categoriesdialog.h"
#include "ui_categoriesdialog.h"
#include <QSqlField>
#include <QSqlRecord>
#include <QMessageBox>

CategoriesDialog::CategoriesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoriesDialog),
    m_categoryId(-1)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

CategoriesDialog::~CategoriesDialog()
{
    delete ui;
}

void CategoriesDialog::setData(const QSqlRecord &record)
{
    m_categoryId = record.value("category_id").toInt();
    ui->lineEditName->setText(record.value("category_name").toString());
    ui->lineEditGenre->setText(record.value("category_genre").toString());
    ui->spinBoxArtists->setValue(record.value("category_artists").toInt());
}

QSqlRecord CategoriesDialog::getData() const
{
    QSqlRecord rec;
    QSqlField fldId("category_id", QVariant::Int);
    if (m_categoryId != -1) fldId.setValue(m_categoryId);
    rec.append(fldId);
    rec.append(QSqlField("category_name", QVariant::String));
    rec.append(QSqlField("category_genre", QVariant::String));
    rec.append(QSqlField("category_artists", QVariant::Int));

    rec.setValue("category_name", ui->lineEditName->text().trimmed());
    rec.setValue("category_genre", ui->lineEditGenre->text().trimmed());
    rec.setValue("category_artists", ui->spinBoxArtists->value());

    return rec;
}

void CategoriesDialog::accept()
{
    if (ui->lineEditName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название категории");
        return;
    }
    if (ui->lineEditGenre->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите жанр");
        return;
    }
    QDialog::accept();
}
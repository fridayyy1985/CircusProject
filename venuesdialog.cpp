#include "venuesdialog.h"
#include "ui_venuesdialog.h"
#include <QSqlField>
#include <QSqlRecord>
#include <QMessageBox>

VenuesDialog::VenuesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VenuesDialog),
    m_venueId(-1)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

VenuesDialog::~VenuesDialog()
{
    delete ui;
}

void VenuesDialog::setData(const QSqlRecord &record)
{
    m_venueId = record.value("venue_id").toInt();
    ui->lineEditName->setText(record.value("venue_name").toString());
    ui->doubleSpinBoxPrice->setValue(record.value("venue_base_price").toDouble());
}

QSqlRecord VenuesDialog::getData() const
{
    QSqlRecord rec;
    QSqlField fldId("venue_id", QVariant::Int);
    if (m_venueId != -1) fldId.setValue(m_venueId);
    rec.append(fldId);
    rec.append(QSqlField("venue_name", QVariant::String));
    rec.append(QSqlField("venue_base_price", QVariant::Double));

    rec.setValue("venue_name", ui->lineEditName->text().trimmed());
    rec.setValue("venue_base_price", ui->doubleSpinBoxPrice->value());

    return rec;
}

void VenuesDialog::accept()
{
    if (ui->lineEditName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название площадки");
        return;
    }
    QDialog::accept();
}
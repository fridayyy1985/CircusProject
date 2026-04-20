#include "showsdialog.h"
#include "ui_showsdialog.h"
#include "databasemanager.h"
#include <QSqlField>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>

ShowsDialog::ShowsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowsDialog),
    m_showId(-1)
{
    ui->setupUi(this);
    loadVenues();
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

ShowsDialog::~ShowsDialog()
{
    delete ui;
}

void ShowsDialog::loadVenues()
{
    QSqlQuery query("SELECT venue_id, venue_name FROM venues ORDER BY venue_name");
    while (query.next()) {
        ui->comboVenue->addItem(query.value(1).toString(), query.value(0));
    }
}

void ShowsDialog::setData(const QSqlRecord &record)
{
    m_showId = record.value("show_id").toInt();
    ui->lineEditName->setText(record.value("show_name").toString());
    int venueId = record.value("venue_id").toInt();
    int idx = ui->comboVenue->findData(venueId);
    if (idx >= 0) ui->comboVenue->setCurrentIndex(idx);
    ui->dateEdit->setDate(record.value("show_date").toDate());
    ui->doubleSpinBoxPrice->setValue(record.value("show_ticket_price").toDouble());
}

QSqlRecord ShowsDialog::getData() const
{
    QSqlRecord rec;
    QSqlField fldId("show_id", QVariant::Int);
    if (m_showId != -1) fldId.setValue(m_showId);
    rec.append(fldId);
    rec.append(QSqlField("show_name", QVariant::String));
    rec.append(QSqlField("venue_id", QVariant::Int));
    rec.append(QSqlField("show_date", QVariant::Date));
    rec.append(QSqlField("show_ticket_price", QVariant::Double));

    rec.setValue("show_name", ui->lineEditName->text().trimmed());
    rec.setValue("venue_id", ui->comboVenue->currentData().toInt());
    rec.setValue("show_date", ui->dateEdit->date());
    rec.setValue("show_ticket_price", ui->doubleSpinBoxPrice->value());

    return rec;
}

void ShowsDialog::accept()
{
    if (ui->lineEditName->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите название шоу");
        return;
    }
    if (ui->comboVenue->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите площадку");
        return;
    }
    QDialog::accept();
}
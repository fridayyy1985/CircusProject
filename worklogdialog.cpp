#include "worklogdialog.h"
#include "ui_worklogdialog.h"
#include "databasemanager.h"
#include <QSqlField>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>

WorkLogDialog::WorkLogDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkLogDialog),
    m_logId(-1)
{
    ui->setupUi(this);
    loadArtists();
    loadShows();
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

WorkLogDialog::~WorkLogDialog()
{
    delete ui;
}

void WorkLogDialog::loadArtists()
{
    QSqlQuery query("SELECT artist_id, artist_fullname FROM artists ORDER BY artist_fullname");
    while (query.next()) {
        ui->comboArtist->addItem(query.value(1).toString(), query.value(0));
    }
}

void WorkLogDialog::loadShows()
{
    QSqlQuery query("SELECT show_id, show_name FROM shows ORDER BY show_name");
    while (query.next()) {
        ui->comboShow->addItem(query.value(1).toString(), query.value(0));
    }
}

void WorkLogDialog::setData(const QSqlRecord &record)
{
    m_logId = record.value("log_id").toInt();
    int artistId = record.value("artist_id").toInt();
    int idx = ui->comboArtist->findData(artistId);
    if (idx >= 0) ui->comboArtist->setCurrentIndex(idx);
    int showId = record.value("show_id").toInt();
    idx = ui->comboShow->findData(showId);
    if (idx >= 0) ui->comboShow->setCurrentIndex(idx);
    ui->doubleSpinBoxPay->setValue(record.value("log_payday").toDouble());
}

QSqlRecord WorkLogDialog::getData() const
{
    QSqlRecord rec;
    QSqlField fldId("log_id", QVariant::Int);
    if (m_logId != -1) fldId.setValue(m_logId);
    rec.append(fldId);
    rec.append(QSqlField("artist_id", QVariant::Int));
    rec.append(QSqlField("show_id", QVariant::Int));
    rec.append(QSqlField("log_payday", QVariant::Double));

    rec.setValue("artist_id", ui->comboArtist->currentData().toInt());
    rec.setValue("show_id", ui->comboShow->currentData().toInt());
    rec.setValue("log_payday", ui->doubleSpinBoxPay->value());

    return rec;
}

void WorkLogDialog::accept()
{
    if (ui->comboArtist->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите артиста");
        return;
    }
    if (ui->comboShow->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите шоу");
        return;
    }
    QDialog::accept();
}
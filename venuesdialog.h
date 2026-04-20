#ifndef VENUESDIALOG_H
#define VENUESDIALOG_H

#include <QDialog>
#include <QSqlRecord>

namespace Ui {
class VenuesDialog;
}

class VenuesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VenuesDialog(QWidget *parent = nullptr);
    ~VenuesDialog();

    void setData(const QSqlRecord &record);
    QSqlRecord getData() const;

private slots:
    void accept() override;

private:
    Ui::VenuesDialog *ui;
    int m_venueId;
};

#endif // VENUESDIALOG_H
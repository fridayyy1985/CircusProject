#ifndef SHOWSDIALOG_H
#define SHOWSDIALOG_H

#include <QDialog>
#include <QSqlRecord>
#include <QDate>

namespace Ui {
class ShowsDialog;
}

class ShowsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowsDialog(QWidget *parent = nullptr);
    ~ShowsDialog();

    void setData(const QSqlRecord &record);
    QSqlRecord getData() const;

private slots:
    void accept() override;

private:
    void loadVenues();

    Ui::ShowsDialog *ui;
    int m_showId;
};

#endif // SHOWSDIALOG_H
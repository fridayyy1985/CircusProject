#ifndef WORKLOGDIALOG_H
#define WORKLOGDIALOG_H

#include <QDialog>
#include <QSqlRecord>

namespace Ui {
class WorkLogDialog;
}

class WorkLogDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkLogDialog(QWidget *parent = nullptr);
    ~WorkLogDialog();

    void setData(const QSqlRecord &record);
    QSqlRecord getData() const;

private slots:
    void accept() override;

private:
    void loadArtists();
    void loadShows();

    Ui::WorkLogDialog *ui;
    int m_logId;
};

#endif // WORKLOGDIALOG_H
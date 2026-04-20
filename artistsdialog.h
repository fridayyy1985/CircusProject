#ifndef ARTISTSDIALOG_H
#define ARTISTSDIALOG_H

#include <QDialog>
#include <QSqlRecord>

namespace Ui {
class ArtistsDialog;
}

class ArtistsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArtistsDialog(QWidget *parent = nullptr);
    ~ArtistsDialog();

    void setData(const QSqlRecord &record);
    QSqlRecord getData() const;

private slots:
    void on_btnBrowsePhoto_clicked();
    void on_btnViewPhoto_clicked();
    void accept() override;

private:
    void loadCategories();

    Ui::ArtistsDialog *ui;
    int m_artistId; // для редактирования
};

#endif // ARTISTSDIALOG_H
#ifndef CATEGORIESDIALOG_H
#define CATEGORIESDIALOG_H

#include <QDialog>
#include <QSqlRecord>

namespace Ui {
class CategoriesDialog;
}

class CategoriesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CategoriesDialog(QWidget *parent = nullptr);
    ~CategoriesDialog();

    void setData(const QSqlRecord &record);
    QSqlRecord getData() const;

private slots:
    void accept() override;

private:
    Ui::CategoriesDialog *ui;
    int m_categoryId;
};

#endif // CATEGORIESDIALOG_H
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    enum Role { Guest, Admin };
    Role userRole() const { return m_role; }

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonCancel_clicked();
    void on_checkBoxGuest_toggled(bool checked);

private:
    Ui::LoginDialog *ui;
    Role m_role;
};

#endif // LOGINDIALOG_H
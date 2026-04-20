#include "logindialog.h"
#include "ui_logindialog.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    m_role(Guest)
{
    ui->setupUi(this);
    on_checkBoxGuest_toggled(ui->checkBoxGuest->isChecked());
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_checkBoxGuest_toggled(bool checked)
{
    ui->lineEditLogin->setEnabled(!checked);
    ui->lineEditPassword->setEnabled(!checked);
    m_role = checked ? Guest : Admin;
}

void LoginDialog::on_pushButtonLogin_clicked()
{
    // Если отмечен чекбокс "Гость" — пропускаем без проверки
    if (ui->checkBoxGuest->isChecked()) {
        m_role = Guest;
        accept();
        return;
    }

    QString login = ui->lineEditLogin->text().trimmed();
    QString password = ui->lineEditPassword->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите логин и пароль");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT Admin_ID FROM accounts WHERE Admin_Login = :login AND Admin_Password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка базы данных: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        m_role = Admin;   // ← устанавливаем роль администратора
        accept();
    } else {
        QMessageBox::warning(this, "Ошибка", "Неверный логин или пароль");
    }
}

void LoginDialog::on_pushButtonCancel_clicked()
{
    reject();
}
#include <QApplication>
#include "mainwindow.h"
#include "logindialog.h"
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Тут вводим свои данные
    if (!DatabaseManager::connect("localhost", 5432, "circus", "postgres", "admin")) {
        return -1;
    }

    LoginDialog login;
    if (login.exec() != QDialog::Accepted) {
        DatabaseManager::close();
        return 0;
    }

    MainWindow w(login.userRole());
    w.show();

    int result = a.exec();
    DatabaseManager::close();
    return result;
}
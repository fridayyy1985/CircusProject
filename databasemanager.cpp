#include "databasemanager.h"
#include <QSqlError>
#include <QMessageBox>

static QSqlDatabase &getDatabase()
{
    static QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    return db;
}

bool DatabaseManager::connect(const QString &host, int port,
                              const QString &dbName,
                              const QString &user, const QString &password)
{
    QSqlDatabase &db = getDatabase();
    db.setHostName(host);
    db.setPort(port);
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(password);
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Ошибка подключения",
                              "Не удалось подключиться к базе данных:\n" + db.lastError().text());
        return false;
    }
    return true;
}

QSqlDatabase DatabaseManager::database() {
    return getDatabase();
}

void DatabaseManager::close() {
    QSqlDatabase &db = getDatabase();
    if (db.isOpen())
        db.close();
}
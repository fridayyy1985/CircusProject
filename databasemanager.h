#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
public:
    static bool connect(const QString &host, int port,
                        const QString &dbName,
                        const QString &user, const QString &password);
    static QSqlDatabase database();
    static void close();
};

#endif // DATABASEMANAGER_H
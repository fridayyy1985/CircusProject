#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSortFilterProxyModel>
#include "logindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlTableModel;
class QTableView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(LoginDialog::Role role, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();
    void on_actionGuide_triggered();
    void onTableSelectionChanged(int index);
    void addRecord();
    void editRecord();
    void deleteRecord();
    void searchTextChanged(const QString &text);

private:
    void setupTableModels();
    void setupTableView(QTableView *view, const QString &tableName);
    QWidget* createTableTab(const QString &tableName);

    Ui::MainWindow *ui;
    LoginDialog::Role m_userRole;
    QMap<QString, QSqlTableModel*> m_models;
    QMap<QString, QSortFilterProxyModel*> m_proxies;
    QMap<QString, QTableView*> m_views;
};

#endif // MAINWINDOW_H
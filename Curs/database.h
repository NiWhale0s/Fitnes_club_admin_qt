#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME "DatabaseAbonement"
#define DATABASE_NAME "database.db"

#define TABLE_ID                "_id"
#define TABLE           "NameTable"
#define TABLE_FNAME     "FirstName"
#define TABLE_SNAME     "SecondName"
#define TABLE_Age       "Age"
#define TABLE_Abonement "Abonement"
#define TABLE_TIMEOUT   "TimeOfUsing"


class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = 0);
    ~database();

    void connectToDataBase();

private:
    QSqlDatabase db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();

public slots:
    bool insertIntoTable(const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);
    bool editInTable(const int &id,const QString &fname, const QString &sname, const QString &age,const QString &abonement, const QString &time);
    bool removeRecord(const int id);
};

#endif // DATABASE_H

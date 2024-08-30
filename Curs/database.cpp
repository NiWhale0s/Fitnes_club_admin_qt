#include "database.h"

database::database(QObject *parent) : QObject(parent)
{

}

database::~database()
{

}

void database::connectToDataBase()
{
    if (!QFile("D:/Curs/database.db").exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool database::restoreDataBase()
{
    if (this->openDataBase()){
        return (this->createTable()) ? true : false;
    } else {
        qDebug() << "Не удалось востановить базу данных";
        return false;
    }
    return false;
}

bool database::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("D:/Curs/database.db");
    if (db.open()){
        return true;
    } else {
        return false;
    }
}

void database::closeDataBase(){
    db.close();
}

bool database::createTable(){
    QSqlQuery query;
    if (!query.exec( "CREATE TABLE IF NOT EXISTS  Abonement   ("
                     "Id  INTEGER PRIMARY KEY AUTOINCREMENT, "
                     "FirstName VARCHAR(255) NOT NULL, "
                     "SecondName VARCHAR(255) NOT NULL, "
                     "age INTEGER NOT NULL, "
                     "Abonement VARCHAR(255) NOT NULL, "
                     "Time VARCHAR (255) NOT NULL"
                     ")"
                     )){
        qDebug() << "Database: error of create" << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }   else {
        return true;
    }
    return false;
}


bool database::insertIntoTable(const QString &fname, const QString &sname, const QString &age, const QString &abonement, const QString &time)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Abonement  ( FirstName , SecondName , Age , Abonement , Time )"
                  "VALUES (:Fname, :Sname, :age ,:Abonement, :Time)");
    query.bindValue(":Fname", fname);
    query.bindValue(":Sname", sname);
    query.bindValue(":age", age);
    query.bindValue(":Abonement", abonement);
    query.bindValue(":Time", time);

    if (query.exec()){
    qDebug() << "error insert now" << TABLE;
    qDebug() << query.lastError().text();
    return false;
}   else {
    return true;
}
return false;
}



bool database::removeRecord(const int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM abonement WHERE Id = :ID;");
    query.bindValue(":ID", id);

    if (query.exec()){
    qDebug() << "error delete row" << TABLE;
    qDebug() << query.lastError().text();
    return false;
}   else {
    return true;
}
return false;

}

bool database::editInTable(const int &id, const QString &fname, const QString &sname, const QString &age, const QString &abonement, const QString &time)
{
    QSqlQuery query;

    query.prepare("UPDATE Abonement SET FirstName =:Fname, SecondName =:Sname, abonement=:Abonement, Age =:age, Time =:Time  WHERE Id =:ID;");
    query.bindValue(":Fname", fname);
    query.bindValue(":Sname", sname);
    query.bindValue(":age", age);
    query.bindValue(":Abonement", abonement);
    query.bindValue(":Time", time);
    query.bindValue(":ID", id);

    if (query.exec()){
    qDebug() << "error insert now" << TABLE;
    qDebug() << query.lastError().text();
    return false;
}   else {
    return true;
}
return false;
}

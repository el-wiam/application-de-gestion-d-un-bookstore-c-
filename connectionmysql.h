#ifndef CONNECTIONMYSQL_H
#define CONNECTIONMYSQL_H


#include<QtSql>
#include "QSqlDatabase"
#include "QSqlQuery"

static bool dbconnected(){
    QSqlDatabase db= QSqlDatabase :: addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setPort(3306);
    db.setDatabaseName("bookshop");
    if(db.open()){
        return true;}
    else {
            return false;
    }
}


#endif // CONNECTIONMYSQL_H

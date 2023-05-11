#ifndef BOOKSHOPMAIN_H
#define BOOKSHOPMAIN_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>
#include"menu.h"
//#include "connectionmysql.h"


namespace Ui {
class bookshopmain;
}

class bookshopmain : public QMainWindow
{
    Q_OBJECT

public:


    explicit bookshopmain(QWidget *parent = nullptr);
    ~bookshopmain();

private slots:
    void on_logbtn_clicked();
    void on_clearlog_clicked();

    void on_exitbtn_clicked();

private:
    Ui::bookshopmain *ui;
    menu *menu;
    QSqlDatabase db;
};

#endif // BOOKSHOPMAIN_H

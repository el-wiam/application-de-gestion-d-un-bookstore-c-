#include<iostream>
#include <QtEndian>
#include "bookshopmain.h"
#include "ui_bookshopmain.h"
#include"menu.h"


bookshopmain::bookshopmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bookshopmain)
{
    ui->setupUi(this);
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("c:/Users/21262/sqllite/bookshop.db");
    if(!db.open()){
        // ui->label1->setText("database is not connected");
          qDebug()<<"database is not connected";
    }
    else {
        //ui->label1->setText("database is connected");
        qDebug()<<"database is connected";
    }
}


bookshopmain::~bookshopmain()
{
    delete ui;

}



void bookshopmain::on_clearlog_clicked()
{
    ui->usernamel->clear();
    ui->passwordl->clear();
}

void bookshopmain::on_logbtn_clicked()
{
    QString username,password;
    username=ui->usernamel->text();
    password = ui->passwordl->text();

    if(!db.isOpen()){
        qDebug()<<"no connectetion to db :(";
        return;
    }

 QSqlQuery qry;
 if(qry.exec("select * from employe where username='"+username+"'and password='"+password+"'")){
    int count = 0;
     while(qry.next()){
      count++;
     }
     if(count==1){
         //ui->label2->setText("username and password are correct");
         hide();
         menu = new class menu(this);
         menu->show();
     }
      if(count>1){
         //ui->label2->setText(" duplicate username and password are correct");
           QMessageBox::critical(this,tr("save"),tr("duplicate username and password are correct"));
     }
     if(count<1){
         //ui->label2->setText("username and password are not correct");
         QMessageBox::critical(this,tr("save"),tr("username and password are not correct"));
   }
     }
 }


void bookshopmain::on_exitbtn_clicked()
{
    close();
}

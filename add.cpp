#include "add.h"
#include "ui_add.h"
#include "menu.h"
#include<QMessageBox>

ADD::ADD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ADD)
{
    ui->setupUi(this);
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("c:/Users/21262/sqllite/bookshop.db");
    /*if(!db.open()){
         ui->label1->setText("database is not connected");
    }
    else {
        ui->label1->setText("database is connected");
    }*/
}

ADD::~ADD()
{
    delete ui;
}


void ADD::on_btnadd_clicked()
{
    QString name = ui->name->text();
    QString author = ui->author->text();
    QString date = ui->date->text();
    QString price = ui->price->text();
    QString status = ui->status->currentText();
        db.open();
    if(!db.isOpen()){
        qDebug()<<"failed to open the database:(";
        return;
    }

    QSqlQuery req;
    req.prepare("insert into book(name,author,date,price,status) values('"+name+"','"+author+"','"+date+"','"+price+"','"+ status+"') ");
    if(req.exec()){
        QMessageBox::critical(this,tr("save"),tr("your data has been added successfully"));
        db.close();
    }
    else {
        QMessageBox::critical(this,tr("error::"),req.lastError().text());
    }
}

void ADD::on_exitbtnn_clicked()
{
    close();
}

void ADD::on_btnclear_clicked()
{
    ui->name->clear();
    ui->author->clear();
    ui->price->clear();
    ui->status->setCurrentText("choices");
}

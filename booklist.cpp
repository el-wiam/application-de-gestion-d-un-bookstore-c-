#include "booklist.h"
#include "ui_booklist.h"
#include"booklist.h"
booklist::booklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::booklist)
{
    ui->setupUi(this);
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("c:/Users/21262/sqllite/bookshop.db");
}

booklist::~booklist()
{
    delete ui;
}

void booklist::on_exitbtn_clicked()
{
    close();
}

void booklist::on_all_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    db.open();
    QSqlQuery * req= new QSqlQuery(db);
    req->prepare("select * from book");
    req->exec();
    modal->setQuery(*req);
    ui->list->setModel(modal);
    db.close();
    qDebug()<<(modal->rowCount());
}

void booklist::on_apply_clicked()
{
    QString status = ui->status->currentText();
    QSqlQueryModel * modal = new QSqlQueryModel();
    db.open();
    QSqlQuery * req= new QSqlQuery(db);
    req->prepare("select * from book where status ='"+status+"';");
    req->exec();
    modal->setQuery(*req);
    ui->list->setModel(modal);
    db.close();
    qDebug()<<(modal->rowCount());
}

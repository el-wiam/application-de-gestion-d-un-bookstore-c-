#include "md.h"
#include "ui_md.h"

md::md(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::md)
{
    ui->setupUi(this);
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("c:/Users/21262/sqllite/bookshop.db");
}

md::~md()
{
    delete ui;
}



void md::on_exitbtn_clicked()
{
    close();
}


void md::on_delete_2_clicked()
{
    QString book=ui->combo->currentText();
    db.open();
   if(!db.isOpen()){
       qDebug()<<"failed to open the database:(";
       return;
   }
   QSqlQuery req;
   req.prepare("delete from book where name='"+book+"';");
   if(req.exec()){
       QMessageBox::critical(this,tr("save"),tr("your data has been deleted successfully"));
       db.close();
   }
   else {
       QMessageBox::critical(this,tr("error::"),req.lastError().text());
   }
}


void md::on_pushButton_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQueryModel * Modal = new QSqlQueryModel();
    db.open();
    QSqlQuery * req= new QSqlQuery(db);
    req->prepare("select * from book");
    req->exec();
    modal->setQuery(*req);
    ui->list->setModel(modal);
    qDebug()<<(modal->rowCount());
    QSqlQuery * qry= new QSqlQuery(db);
    qry->prepare("select name from book");
    qry->exec();
    Modal->setQuery(*qry);
    ui->combo->setModel(Modal);
    db.close();
}

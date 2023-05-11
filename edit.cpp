#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
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

edit::~edit()
{
    delete ui;
}

void edit::on_edit_2_clicked()
{
    QString name = ui->name->text();
    QString author = ui->author->text();
    QString date = ui->date->text();
    QString price = ui->price->text();
    QString status = ui->status->currentText();
    QString id = ui->id->text();
        db.open();
    if(!db.isOpen()){
        qDebug()<<"failed to open the database:(";
        return;
    }
    QSqlQuery req;
    //req.prepare(" update book set  name='"+name+"',author='"+author+"',date'"+date+"',price'"+price+"',status='"+status+"' where id_book='"+id+"';");
    if(req.exec(" update book set  name='"+name+"',author='"+author+"',date='"+date+"',price='"+price+"',status='"+status+"' where id_book='"+id+"';")){
        QMessageBox::critical(this,tr("edit"),tr("your data has been edited successfully"));
        db.close();
    }
    else {
        QMessageBox::critical(this,tr("error::"),req.lastError().text());
    }
}

void edit::on_exitbtnn_clicked()
{
    close();
}

void edit::on_apply_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    db.open();
    QSqlQuery * req= new QSqlQuery(db);
    req->prepare("select name from book;");
    req->exec();
    modal->setQuery(*req);
    ui->combo->setModel(modal);
    db.close();
    qDebug()<<(modal->rowCount());
}

void edit::on_combo_currentIndexChanged(const QString &arg1)
{
         QString book=ui->combo->currentText();
         db.open();
        if(!db.isOpen()){
            qDebug()<<"failed to open the database:(";
            return;
        }
        QSqlQuery req;
        req.prepare("select * from book where name='"+book+"';");
        if(req.exec()){
            while(req.next()){
                ui->id->setText(req.value(0).toString());
                ui->name->setText(req.value(1).toString());
                ui->author->setText(req.value(2).toString());
                //ui->date->setDate(req.value(3).toString());
                ui->price->setText(req.value(4).toString());
                //ui->status->setCurrentText(req.value(5).toString());
            }
            db.close();
        }
        else {
            QMessageBox::critical(this,tr("error::"),req.lastError().text());
        }



}

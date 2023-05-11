#include "menu.h"
#include "ui_menu.h"
#include"add.h"
#include "md.h"
#include "booklist.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_addbtn_clicked()
{
        ADD = new class ADD(this);
        ADD->show();
}

void menu::on_exitbtn_clicked()
{
    close();
}

void menu::on_deletebtn_clicked()
{
    md = new class md(this);
    md->show();
}

void menu::on_modbtn_clicked()
{
    edit = new class edit(this);
    edit->show();
}

void menu::on_booklist_clicked()
{
    booklist = new class booklist(this);
    booklist->show();
}

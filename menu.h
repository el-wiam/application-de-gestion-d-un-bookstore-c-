#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include"add.h"
#include "md.h"
#include "booklist.h"
#include"edit.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_addbtn_clicked();

    void on_exitbtn_clicked();

    void on_deletebtn_clicked();

    void on_modbtn_clicked();

    void on_booklist_clicked();

private:
    Ui::menu *ui;
    ADD *ADD;
    md *md;
    edit *edit;
    booklist *booklist;
};

#endif // MENU_H

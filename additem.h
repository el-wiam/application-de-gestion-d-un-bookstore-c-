#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>


namespace Ui {
class additem;
}

class additem : public QDialog
{
    Q_OBJECT

public:
    explicit additem(QWidget *parent = nullptr);
    ~additem();

private slots:
    void on_push_clicked();

private:
    Ui::additem *ui;
};

#endif // ADDITEM_H

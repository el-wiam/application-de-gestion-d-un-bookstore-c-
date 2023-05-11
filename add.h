#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class ADD;
}

class ADD : public QDialog
{
    Q_OBJECT

public:
    explicit ADD(QWidget *parent = nullptr);
    ~ADD();

private slots:
    void on_btnadd_clicked();

    void on_exitbtnn_clicked();

    void on_btnclear_clicked();

private:
    Ui::ADD *ui;
    QSqlDatabase db;

};

#endif // ADD_H

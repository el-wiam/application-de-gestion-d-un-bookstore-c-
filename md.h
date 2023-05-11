#ifndef MD_H
#define MD_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>
#include"edit.h"

namespace Ui {
class md;
}

class md : public QDialog
{
    Q_OBJECT

public:
    explicit md(QWidget *parent = nullptr);
    ~md();

private slots:

    void on_exitbtn_clicked();

    void on_delete_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::md *ui;
    QSqlDatabase db;
    edit *edit;
};

#endif // MD_H

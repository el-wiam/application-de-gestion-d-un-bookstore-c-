#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>


namespace Ui {
class booklist;
}

class booklist : public QDialog
{
    Q_OBJECT

public:
    explicit booklist(QWidget *parent = nullptr);
    ~booklist();

private slots:
    void on_exitbtn_clicked();

    void on_all_clicked();

    void on_apply_clicked();

private:
    Ui::booklist *ui;
    QSqlDatabase db;
};

#endif // BOOKLIST_H

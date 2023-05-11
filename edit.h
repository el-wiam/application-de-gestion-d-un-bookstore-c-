#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMessageBox>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void on_edit_2_clicked();

    void on_exitbtnn_clicked();

    void on_apply_clicked();

    void on_combo_currentIndexChanged(const QString &arg1);

private:
    Ui::edit *ui;
    QSqlDatabase db;
};

#endif // EDIT_H

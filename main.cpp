#include "bookshopmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bookshopmain w;
    w.show();

    return a.exec();
}

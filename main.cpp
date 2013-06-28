#include "mainviewwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainviewwidget w;
    w.setMinimumSize(350,150);
    w.show();
    return a.exec();
}


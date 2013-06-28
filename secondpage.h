#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QWidget>
#include <QtGui>
#include "model.h"

class SecondPage : public QWidget
{
    Q_OBJECT
public:
    explicit SecondPage(Model *model, QWidget *parent = 0);
    
signals:
    
public slots:
private slots:
    void addDeveloper();
    void editDeveloper();
    void deleteDeveloper();
private:
    Model *const model;
    QListWidget *list1;
    QVBoxLayout *mainlayout2;
    QHBoxLayout *buttonslayout;
    QPushButton *adddeveloper;
    QPushButton *editdeveloper;
    QPushButton *deletedeveloper;

    
};

#endif // SECONDPAGE_H

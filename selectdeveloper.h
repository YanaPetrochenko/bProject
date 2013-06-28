#ifndef SELECTDEVELOPER_H
#define SELECTDEVELOPER_H

#include <QDialog>
#include <QtGui>
#include "developer.h"

class SelectDeveloper : public QDialog
{
    Q_OBJECT
public:
    explicit SelectDeveloper(Developer *current,QVector<Developer *> * available,QWidget *parent = 0);
    ~SelectDeveloper();
    Developer *selected();
    
signals:
    
public slots:
private slots:
    void confirm();
private:
    QPushButton*ok;
    QPushButton*cancel;
    QComboBox*combobox;
    QVBoxLayout*mainlayout;
    QHBoxLayout*buttonlayout;
    QVector<Developer *> *list;
    QVector<Developer *> *available;
    Developer *current;

    
};

#endif // SELECTDEVELOPER_H

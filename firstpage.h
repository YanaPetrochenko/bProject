#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QWidget>
#include <QtGui>
#include "model.h"

class FirstPage : public QWidget
{
    Q_OBJECT
public:
    explicit FirstPage(Model*model,QWidget *parent = 0);
    
signals:
    
public slots:
private slots:
    void apply();
private:
    Model *const model;
    QLineEdit *display1;
    QTimeEdit *time;
    QDateEdit *data;
    QHBoxLayout *timing;
    QPushButton *then;
   // QPushButton*arrowright;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonLayout;
    QSignalMapper *mapper;
    QLabel *nameproject;
    QLabel *timebeginning;
};

#endif // FIRSTPAGE_H

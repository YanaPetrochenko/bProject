#ifndef MAINVIEWWIDGET_H
#define MAINVIEWWIDGET_H

#include <QWidget>
#include <QtGui>
#include "firstpage.h"
#include "secondpage.h"
#include "thirdpage.h"
#include "model.h"
#include "resultwidget.h"
class mainviewwidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainviewwidget(QWidget *parent = 0);
    ~mainviewwidget();
    
signals:
    
public slots:
private slots:
    void addresult();
private:
    Model*model;
    QVBoxLayout *mainmainlayout;
    QHBoxLayout *resultbutton;
    QTabWidget *tabwidget;
    FirstPage *page1;
    SecondPage *page2;
    ThirdPage *page3;
    QPushButton *calculate;
    
};

#endif // MAINVIEWWIDGET_H

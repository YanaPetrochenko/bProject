#ifndef THIRDPAGE_H
#define THIRDPAGE_H

#include <QWidget>
#include <QtGui>
#include "model.h"

class ThirdPage : public QWidget
{
    Q_OBJECT
public:
    explicit ThirdPage(Model *model, QWidget *parent = 0);

signals:
    
public slots:
private slots:
    void addTask();
    void editTask();
    void deleteTask();
private:
    Model *const model;
    QVBoxLayout *mainlayout3;
    QHBoxLayout *buttonlayout3;
    QListWidget *list3;
    QPushButton *addtask;
    QPushButton *edittask;
    QPushButton *deletetask;
};

#endif // THIRDPAGE_H

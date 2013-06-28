#ifndef TASKENTER_H
#define TASKENTER_H

#include <QtGui>
#include "task.h"
#include "model.h"

class TaskEnter : public QDialog
{
    Q_OBJECT
public:
    explicit TaskEnter(Task *task, Model *model,QWidget *parent = 0);
    ~TaskEnter();
    QString name() const;
    int duration() const;
    QVector<Developer*> *getDevelopers();
    QVector<Task*> *getDependences();
    
signals:
    
public slots:
private slots:
    void changeDeveloperCount(int newCountDeveloper);
    void changeDependenceCount(int newCountDependence);
private:
    Task *task;
    Model *const model;
    int numberDevelopers, numberDependences;
    QLineEdit *display;
    QLabel *nametask, *durationLabel;
    QSpinBox *countdevelopers;
    QSpinBox *countdependence;
    QVBoxLayout *mainLayout;
    QGroupBox *developersGroup;
    QGroupBox *dependencesGroup;
    QHBoxLayout *groups, *buttonsLayout;
    QVBoxLayout *developerlayout;
    QVBoxLayout *taskslayout;
    QGroupBox *taskduration;
    QHBoxLayout *groupsduration;
    QVBoxLayout *days;
    QVBoxLayout *hours;
    QGroupBox *namedays;
    QGroupBox *namehours;
    QSpinBox *spinday;
    QSpinBox *spinhours;
    //QSpinBox *spinbox1;
    //QSpinBox *spinbox2;
    QVector<QComboBox *> developers, dependences;
    QPushButton *ok;
    QPushButton *cancel;
    
};

#endif // TASKENTER_H

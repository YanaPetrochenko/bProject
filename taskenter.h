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
    void addDeveloperSlot();
    void editDeveloperSlot();
    void deleteDeveloperSlot();
    void addDependenceSlot();
    void editDependenceSlot();
    void deleteDependenceSlot();
private:
    Task *task;
    Model *const model;
    QVector<Developer *> *futureDeveloper;
    QVector<Developer *> *availableDeveloper;
    QVector<Task *> *futureDependences;
    QVector<Task *> *availableTasks;
    int numberDevelopers, numberDependences;
    QLineEdit *display;
    QLabel *nametask, *durationLabel;
   // QSpinBox *countdevelopers;
   // QSpinBox *countdependence;
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
    QListWidget*dependences;
    QListWidget*developers;
    QPushButton*adddeveloper;
    QPushButton*editdeveloper;
    QPushButton*deletedeveloper;
    QPushButton*adddependence;
    QPushButton*editdependence;
    QPushButton*deletedependence;
    QHBoxLayout*developersbuttonlayout;
    QHBoxLayout*dependencesbuttonlayout;
    //QSpinBox *spinbox1;
    //QSpinBox *spinbox2;
    //QVector<QComboBox *> developers, dependences;
    QPushButton *ok;
    QPushButton *cancel;
    
};

#endif // TASKENTER_H

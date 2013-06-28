#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QVector>
#include <QDateTime>
#include "developer.h"

class Model;
class Task
{
    friend class Model;
public:
    Task();
    Task(const QString &nameOfTask, int duration, QVector<Developer *> *developer, QVector<Task *> *dependences);
    QString name() const;
    void setName(const QString &name);
    int duration() const;
    void setDuration(int duration) ;
    QVector<Developer *> *&developers();
    QVector<Task *> *&dependences();
    QString toString();
    void reset();
private:

    QString nameOfTask;
    int durationHours;
    QVector<Developer *> *developers_;
    QVector<Task *> *dependences_;

    QDateTime startTime, endTime;
    int deepness;
    Task *parent;

};

#endif // TASK_H

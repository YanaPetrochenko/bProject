#include "task.h"
Task::Task()
{
    nameOfTask="0";
    durationHours=0;
    dependences_= new (QVector<Task *>);
    developers_=new (QVector<Developer *>);
    parent=0;
    deepness=0;

}
Task::Task(const QString &nameOfTask, int duration,  QVector<Developer *> *developers,  QVector<Task *> *dependences):
    nameOfTask(nameOfTask),
    durationHours(duration),
    developers_(developers),
    dependences_(dependences),
    deepness(0),
    parent(0)
{
}

QString Task::name() const
{
    return nameOfTask;
}

void Task::setName(const QString &name)
{
    nameOfTask=name;

}

int Task::duration() const
{
    return durationHours;
}

void Task::setDuration(int duration)
{
    durationHours=duration;
}
QVector<Developer *> *Task::developers()
{
    return developers_;
}
QVector<Task *> *Task::dependences()
{
    return dependences_;

}

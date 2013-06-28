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
QVector<Developer *> *&Task::developers()
{
    return developers_;
}
QVector<Task *> *&Task::dependences()
{
    return dependences_;

}

void Task::reset()
{
    deepness=0;
    parent=0;
}

QString Task::toString()
{
    QString str;
    str=nameOfTask;
    str+=QString().append(" %1h").arg(durationHours);
    str+="   (";
    for(int i=0;i<developers_->size()-1;++i)
        str+=developers_->at(i)->name()+", ";
    str+=developers_->at(developers_->size()-1)->name()+") ";
    if(dependences_->size()>0)
    {
        str+=": ";
        for(int i=0;i<dependences_->size()-1;++i)
            str+=dependences_->at(i)->name()+", ";
         str+=dependences_->at(dependences_->size()-1)->name()+".";
    }

    if(deepness)
    {
      str+="\n    ";
      str+=QString().append("level:%1  start:%2 finish:%3").arg(deepness).arg(startTime.toString("dd hh:mm")).arg(endTime.toString("dd hh:mm"));
    }
    return str;
}

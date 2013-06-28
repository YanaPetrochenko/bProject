
#include "model.h"
#include <QDebug>

Model::Model():
    developers_(new QVector<Developer*>),
    tasks_(new QVector<Task*>),
    parent(0)

{
}
Model::~Model()
{
    for(int i=0; i<developers_->size(); ++i)
        delete developers_->at(i);
    for(int i=0; i<tasks_->size(); ++i)
        delete tasks_->at(i);
    developers_->clear();
    tasks_->clear();
    delete developers_;
    delete tasks_;
}

QVector<Developer *> *&Model::developers()
{
    return developers_;
}

QVector<Task *> *&Model::tasks()
{
    return tasks_;
}

QString &Model::name()
{
    return nameofproject;
}

QDateTime &Model::startDateTime()
{
    return startDateTime_;
}

QDateTime &Model::endDateTime()
{
   return endDateTime_;
}
template<class T>
inline T max(T a,T b)
{
    return a>b?a:b;
}
void Model:: calculate()
{
    endDateTime_=startDateTime_;
    QDateTime retTime=startDateTime_;
    for(int i=0;i<tasks_->size();++i)
    {
        tasks_->at(i)->reset();
    }
    for(int i=0;i<tasks_->size();++i)
    {
        dfs(tasks_->at(i),retTime);

        if(retTime>endDateTime_)
       {
            endDateTime_=retTime;
            parent=tasks_->at(i);
        }
    }
}


int Model:: dfs(Task* vertex,QDateTime &bEnd)
{
    if(vertex->deepness==0)
    {

        int result=0;
        vertex->parent=0;
        QDateTime resultTime=startDateTime_;
        for(int i=0;i<vertex->dependences_->size();++i)
        {
            QDateTime retTime;
            int retDeep=dfs(vertex->dependences_->at(i),retTime);
            if(retTime>resultTime)
            {
                resultTime=retTime;
                vertex->parent=vertex->dependences_->at(i);
            }
            result=max(result,retDeep);
        }
        vertex->startTime=resultTime;
        vertex->endTime=vertex->startTime;
        vertex->endTime=vertex->endTime.addDays(vertex->durationHours/24);
        vertex->endTime=vertex->endTime.addSecs((vertex->durationHours%24)*3600);
        vertex->deepness=result+1;
    }
    bEnd=vertex->endTime;
    return vertex->deepness;
}
void Model::output()
{
    qDebug()<<"Timebeginning of project "<<startDateTime_;
    for(int i=0;i<tasks_->size();++i)
    {
        qDebug()<<tasks_->at(i)->nameOfTask<<" "<<tasks_->at(i)->deepness;
        qDebug()<<tasks_->at(i)->startTime<<" -> "<<tasks_->at(i)->endTime;
        //qDebug()<<tasks_->at(i)->parent;


    }
    qDebug()<<"Timeending of project "<<endDateTime_;
   // qDebug()<<"\n\n\ criticalpath:";
    criticalpath(parent);
}
Task *Model::criticalpath(Task *vertex)
 {


       return vertex->parent;

 }

Task* Model::root()
{
    return parent;
}

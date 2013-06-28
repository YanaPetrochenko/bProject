#ifndef MODEL_H
#define MODEL_H

#include<QVector>
#include<QDateTime>
#include<../b-project/developer.h>
#include<../b-project/task.h>


class Model
{
public:
    Model();
    ~Model();
    QVector<Developer*> *&developers();
    QVector<Task *> *&tasks();
    QString &name();
    QDateTime &startDateTime();
    QDateTime &endDateTime();
    void calculate();
    void output();
    Task* criticalpath(Task *vertex);
    Task* root();
private:
    QString nameofproject;
    QDateTime startDateTime_;
    QDateTime endDateTime_;
    QVector<Developer*> *developers_;
    QVector<Task*> *tasks_;
    Task *parent;
    int dfs(Task* vertex,QDateTime &bEnd);
};

#endif // MODEL_H

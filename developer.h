#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QString>

class Developer
{
public:
    Developer(const QString &name);
    void setName(const QString &name);
    QString name() const;
private:
    QString name_;
    //Developer*parent;
};

#endif // DEVELOPER_H
/*
при чем тут только тогда когда я обращалась
20:10:53
изначально у тебя был мотив т.к. ты думал что у нас будут отношения?
я же тебе сразу сказала , что у меня есть парень.ямогла тебе предложить только дружбу.чего собственно я и хотела*/

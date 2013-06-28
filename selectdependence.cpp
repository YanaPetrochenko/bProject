#include "selectdependence.h"
#include <QDebug>

SelectDependence::SelectDependence(Task *current, QVector<Task *> *available,QWidget *parent) :
    QDialog(parent),
    ok(new QPushButton("Ok")),
    cancel(new QPushButton("Cancel")),
    combobox(new QComboBox),
    mainlayout(new QVBoxLayout),
    buttonlayout(new QHBoxLayout),
    current(current),
    available(available)

{
    setModal(true);
    setLayout(mainlayout);
    mainlayout->addWidget(combobox);
    mainlayout->addLayout(buttonlayout);
    buttonlayout->addWidget(ok);
    buttonlayout->addWidget(cancel);

    list = new QVector<Task *>;
    list->push_back(current);
    for(int i=0;i<available->size();++i)
        list->push_back(available->at(i));


    for(int i=0;i<list->size();++i)
    {
        if(list->at(i))
            combobox->addItem(list->at(i)->name());
        else
            combobox->addItem("");
    }


    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(confirm()));
    QObject::connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));
}

SelectDependence::~SelectDependence()
{
    list->clear();
    delete list;
}

void SelectDependence::confirm()
{
    int index;
    if((index=combobox->currentIndex())>=0)
    {
        qDebug()<<index;
        current=list->at(index);
        qDebug()<<current;
        if(current)
            qDebug()<<current->toString();
        available->clear();
        for(int i=0;i<list->size();++i)
        {
            if(i!=index&&list->at(i))
                available->push_back(list->at(i));
        }
    }
    accept();
}

Task *SelectDependence::selected()
{
    return current;
}


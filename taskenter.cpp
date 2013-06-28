#include "taskenter.h"


TaskEnter::TaskEnter(Task *task, Model *model, QWidget *parent) :
    QDialog(parent),
    task(task),
    model(model),
    numberDevelopers(3),
    numberDependences(6),
    display(new QLineEdit()),
    mainLayout(new QVBoxLayout()),
    taskduration(new QGroupBox("Duration")),
    groupsduration(new QHBoxLayout),
    days(new QVBoxLayout),
    hours(new QVBoxLayout),
    namedays(new QGroupBox("Days")),
    namehours(new QGroupBox("Hours")),
    spinday(new QSpinBox),
    spinhours(new QSpinBox),
    //spinbox1(new QSpinBox()),
    //spinbox2(new QSpinBox()),
    nametask(new QLabel("Name of task")),
    countdevelopers(new QSpinBox),
    countdependence(new QSpinBox),
    developersGroup(new QGroupBox("Developers")),
    dependencesGroup(new QGroupBox("Dependences")),
    groups(new QHBoxLayout),
    developerlayout(new QVBoxLayout),
    taskslayout(new QVBoxLayout),
    buttonsLayout(new QHBoxLayout),
    ok(new QPushButton("Ok")),
    cancel(new QPushButton("Cancel"))
{
    countdevelopers->setRange(1,5);
    countdependence->setRange(0,10);

    if(task)
    {
        display->setText(task->name());
        spinday->setValue(task->duration()/24);
        spinhours->setValue(task->duration()%24);
        numberDevelopers=task->developers()->size();
        countdevelopers->setValue(numberDevelopers);
        for(int i=0; i<countdevelopers->value(); ++i)
            developers.push_back(new QComboBox);
        numberDependences = task->dependences()->size();
        countdependence->setValue(numberDependences);
        for(int i=0;i<countdependence->value();++i)
            dependences.push_back(new QComboBox);
    }
    else
    {


    countdevelopers->setValue(numberDevelopers);
    for(int i=0; i<countdevelopers->value(); ++i)
        developers.push_back(new QComboBox);


    countdependence->setValue(numberDependences);
    for(int i=0;i<countdependence->value();++i)
        dependences.push_back(new QComboBox);

    }
    spinhours->setRange(0,24);
    setLayout(mainLayout);
  /*  mainLayout->addWidget(nametask);
    mainLayout->addWidget(display);
    mainLayout->addWidget(taskduration);
    taskduration->setLayout(groupsduration);
    groupsduration->addWidget(namedays);
    groupsduration->addWidget(namehours);
    namedays->setLayout(days);
    days->addWidget(spinday);
    namehours->setLayout(hours);
    hours->addWidget(spinhours);*/

    mainLayout->addLayout(groups);
    mainLayout->addSpacerItem(new QSpacerItem(0,30,QSizePolicy::Minimum,QSizePolicy::Expanding));
    mainLayout->addLayout(buttonsLayout);


    groups->addWidget(developersGroup);
    groups->addWidget(dependencesGroup);

    developersGroup->setLayout(developerlayout);

    developerlayout->addWidget(countdevelopers);
    for(int i=0;i<developers.size();++i)
        developerlayout->addWidget(developers.at(i));
    developerlayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));


    dependencesGroup->setLayout(taskslayout);

    taskslayout->addWidget(countdependence);
    for(int i=0;i<dependences.size();++i)
        taskslayout->addWidget(dependences.at(i));
    taskslayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));


    buttonsLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding));
    buttonsLayout->addWidget(ok);
    buttonsLayout->addWidget(cancel);

    if(task)
    {
        for(int i=0; i<countdevelopers->value(); ++i)
            developers.at(i)->insertItem(0,task->developers()->at(i)->name());
        for(int i=0;i<dependences.size();++i)
            dependences.at(i)->insertItem(0,task->dependences()->at(i)->name());
    }

    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));

    QObject::connect(countdevelopers,SIGNAL(valueChanged(int)),this,SLOT(changeDeveloperCount(int)));
    QObject::connect(countdependence,SIGNAL(valueChanged(int)),this,SLOT(changeDependenceCount(int)));
}

TaskEnter::~TaskEnter()
{
    for(int i=0; i<developers.size(); ++i)
        delete developers.at(i);
    for(int i=0; i<dependences.size(); ++i)
        delete dependences.at(i);
    developers.clear();
    dependences.clear();
}

void TaskEnter::changeDeveloperCount(int newCountDeveloper)
{
    if(newCountDeveloper>numberDevelopers)
    {

        for(int i=numberDevelopers; i<newCountDeveloper; ++i)
        {
            developers.push_back(new QComboBox);
            developerlayout->insertWidget(developerlayout->count()-1,developers.at(i));
        }

    }
    else if (newCountDeveloper<numberDevelopers)
    {
        for(int i=numberDevelopers-1; i>=newCountDeveloper; --i)
        {
            delete developers.at(i);
            developers.pop_back();
        }
    }
    numberDevelopers = newCountDeveloper;
}
 void TaskEnter::changeDependenceCount(int newCountDependence)
 {
     if(newCountDependence>numberDependences)
     {
         for(int i=numberDependences;i<newCountDependence;++i)
         {
             dependences.push_back(new QComboBox);
             taskslayout->insertWidget(taskslayout->count()-1,dependences.at(i));
         }

     }
     else if(newCountDependence<numberDependences)
     {
         for(int i=numberDependences-1;i>=newCountDependence;--i)
         {
             delete dependences.at(i);
             dependences.pop_back();
         }
     }
     numberDependences=newCountDependence;
 }

 QString TaskEnter::name() const
 {
     return display->text();
 }
 int TaskEnter::duration() const
 {
     return spinday->value()*24+spinhours->value();

 }

 QVector<Developer*> *TaskEnter::getDevelopers()
 {
    return new QVector<Developer*>;
 }

 QVector<Task*> *TaskEnter::getDependences()
 {
     return new QVector<Task*>;
 }

/*
void TaskEnter::confirm()
{
    QVector<Developer *> dvlp;
    QVector<Task *> dpnd;
    for(int i=0; i< developers.size(); ++i)
        dvlp.push_back(new Developer(developers.at(i)->currentText()));
   // task= new Task(display->text(),spinday->value()*24+spinhours->value(),dvlp,dpnd);
    accept();
}
*/

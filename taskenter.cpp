#include "taskenter.h"
#include "selectdeveloper.h"
#include "selectdependence.h"
#include "QDebug"


TaskEnter::TaskEnter(Task *task, Model *model, QWidget *parent) :
    QDialog(parent),
    task(task),
    model(model),
    availableDeveloper(new QVector<Developer *>),
    availableTasks(new QVector<Task *>),
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
   // countdevelopers(new QSpinBox),
   // countdependence(new QSpinBox),
    developersGroup(new QGroupBox("Developers")),
    dependencesGroup(new QGroupBox("Dependences")),
    groups(new QHBoxLayout),
    developerlayout(new QVBoxLayout),
    taskslayout(new QVBoxLayout),
    buttonsLayout(new QHBoxLayout),
    dependences(new QListWidget),
    developers(new QListWidget),
    adddeveloper(new QPushButton("add")),
    editdeveloper(new QPushButton("edit")),
    deletedeveloper(new QPushButton("delete")),
    adddependence(new QPushButton("add")),
    editdependence(new QPushButton("edit")),
    deletedependence(new QPushButton("delete")),
    developersbuttonlayout(new QHBoxLayout),
    dependencesbuttonlayout(new QHBoxLayout),
    ok(new QPushButton("Ok")),
    cancel(new QPushButton("Cancel"))
{
    //countdevelopers->setRange(1,5);
    //countdependence->setRange(0,10);

    if(task)
    {
        setModal(true);
        display->setText(task->name());
        spinday->setValue(task->duration()/24);
        spinhours->setValue(task->duration()%24);
        futureDeveloper = task->developers();
        for( int i=0; i<model->developers()->size();++i)
            if(!futureDeveloper->contains(model->developers()->at(i)))
                availableDeveloper->push_back(model->developers()->at(i));


        futureDependences = task->dependences();
        for( int i=0; i<model->tasks()->size();++i)
            if(!futureDependences->contains(model->tasks()->at(i))&&model->tasks()->at(i)!=task)
                availableTasks->push_back(model->tasks()->at(i));
    }
    else
    {

        futureDeveloper =new QVector<Developer *>;
        for( int i=0; i<model->developers()->size();++i)
            availableDeveloper->push_back(model->developers()->at(i));

        futureDependences = new QVector<Task *>;
        for( int i=0; i<model->tasks()->size();++i)
            if(model->tasks()->at(i)!=task)
                availableTasks->push_back(model->tasks()->at(i));
    }
    for(int i=0;i<futureDeveloper->size();++i)
    {
        developers->addItem(futureDeveloper->at(i)->name());
    }
    for(int i=0;i<futureDependences->size();++i)
    {
        dependences->addItem(futureDependences->at(i)->name());
    }

    spinhours->setRange(0,24);
    setLayout(mainLayout);
    mainLayout->addWidget(nametask);
    mainLayout->addWidget(display);
    mainLayout->addWidget(taskduration);
    taskduration->setLayout(groupsduration);
    groupsduration->addWidget(namedays);
    groupsduration->addWidget(namehours);
    namedays->setLayout(days);
    days->addWidget(spinday);
    namehours->setLayout(hours);
    hours->addWidget(spinhours);

    mainLayout->addLayout(groups);
    mainLayout->addSpacerItem(new QSpacerItem(0,30,QSizePolicy::Minimum,QSizePolicy::Expanding));
    mainLayout->addLayout(buttonsLayout);


    groups->addWidget(developersGroup);
    groups->addWidget(dependencesGroup);

    developersGroup->setLayout(developerlayout);
    developerlayout->addWidget(developers);
    developerlayout->addLayout(developersbuttonlayout);
    developersbuttonlayout->addWidget(adddeveloper);
    developersbuttonlayout->addWidget(editdeveloper);
     developersbuttonlayout->addWidget(deletedeveloper);


    dependencesGroup->setLayout(taskslayout);
    taskslayout->addWidget(dependences);
    taskslayout->addLayout(dependencesbuttonlayout);
    dependencesbuttonlayout->addWidget(adddependence);
    dependencesbuttonlayout->addWidget(editdependence);
    dependencesbuttonlayout->addWidget(deletedependence);

    buttonsLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding));
    buttonsLayout->addWidget(ok);
    buttonsLayout->addWidget(cancel);

    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect(adddeveloper,SIGNAL(clicked()),this,SLOT(addDeveloperSlot()));
    QObject::connect(editdeveloper,SIGNAL(clicked()),this,SLOT(editDeveloperSlot()));
    QObject::connect(deletedeveloper,SIGNAL(clicked()),this,SLOT(deleteDeveloperSlot()));
    QObject::connect(adddependence,SIGNAL(clicked()),this,SLOT(addDependenceSlot()));
    QObject::connect(editdependence,SIGNAL(clicked()),this,SLOT(editDependenceSlot()));
    QObject::connect(deletedependence,SIGNAL(clicked()),this,SLOT(deleteDependenceSlot()));
}

TaskEnter::~TaskEnter()
{

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
    return futureDeveloper;
 }

 QVector<Task*> *TaskEnter::getDependences()
 {
     return futureDependences;
 }

 void TaskEnter::addDeveloperSlot()
 {
     Developer *developer=0;
     SelectDeveloper *dialog = new SelectDeveloper(developer,availableDeveloper);
     int result = dialog->exec();
     if(result)
     {
        developer=dialog->selected();
        if(developer)
        {

            futureDeveloper->push_back(developer);
            developers->addItem(developer->name());
        }
     }
     delete dialog;
 }

 void TaskEnter::editDeveloperSlot()
 {
     if(developers->selectedItems().size()==1)
    {
        Developer *developer = futureDeveloper->at(developers->currentRow());
        SelectDeveloper *dialog = new SelectDeveloper(developer,availableDeveloper);
        int result = dialog->exec();
        if(result)
        {
           developer=dialog->selected();
           futureDeveloper->replace(developers->currentRow(),developer);
           developers->currentItem()->setText(developer->name());
        }
        delete dialog;
    }
 }


 void TaskEnter::deleteDeveloperSlot()
 {
     if(developers->selectedItems().size()==1)
     {
         int index = developers->currentRow();
         Developer *developer = futureDeveloper->at(index);
         QListWidgetItem *item = developers->item(index);
         developers->removeItemWidget(item);
         delete item;

         futureDeveloper->remove(index);
         availableDeveloper->push_back(developer);
     }
 }

 void TaskEnter::addDependenceSlot()
 {
     Task *parent=0;
     SelectDependence *dialog = new SelectDependence(parent,availableTasks);
     int result = dialog->exec();
     if(result)
     {
        parent=dialog->selected();
        if(parent)
        {

            futureDependences->push_back(parent);
            dependences->addItem(parent->toString());
        }
     }
     delete dialog;
 }

 void TaskEnter::editDependenceSlot()
 {
     if(dependences->selectedItems().size()==1)
     {
         Task *parent=futureDependences->at(dependences->currentRow());
         SelectDependence *dialog = new SelectDependence(parent,availableTasks);
         int result = dialog->exec();
         if(result)
         {
            parent=dialog->selected();
            if(parent)
            {
                parent=dialog->selected();
                futureDependences->replace(dependences->currentRow(),parent);
                dependences->currentItem()->setText(parent->toString());
            }
         }
         delete dialog;
     }
 }

 void TaskEnter::deleteDependenceSlot()
 {
     if(dependences->selectedItems().size()==1)
     {
         int index = dependences->currentRow();
         Task *parent = futureDependences->at(index);
         QListWidgetItem *item = dependences->item(index);
         dependences->removeItemWidget(item);
         delete item;

         futureDependences->remove(index);
         availableTasks->push_back(parent);
     }
 }


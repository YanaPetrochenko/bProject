#include "thirdpage.h"
#include "taskenter.h"
#include "task.h"

ThirdPage::ThirdPage(Model *model,QWidget *parent) :
    QWidget(parent),
    model(model),
    mainlayout3(new QVBoxLayout),
    buttonlayout3(new QHBoxLayout),
    list3(new QListWidget),
    addtask(new QPushButton("add")),
    edittask(new QPushButton("edit")),
    deletetask(new QPushButton("delete"))


{
    setLayout(mainlayout3);
    mainlayout3->addWidget(list3);
    mainlayout3->addLayout(buttonlayout3);
    buttonlayout3->addWidget(addtask);
    buttonlayout3->addWidget(edittask);
    buttonlayout3->addWidget(deletetask);


    QObject::connect(addtask,SIGNAL(clicked()),this,SLOT(addTask()));
    QObject::connect(edittask,SIGNAL(clicked()),this,SLOT(editTask()));
    QObject::connect(deletetask,SIGNAL(clicked()),this,SLOT(deleteTask()));
}

void ThirdPage::addTask()
{
    Task *task=0;
    TaskEnter *enter= new TaskEnter(task,model);
    int result = enter->exec();
    if(result)
    {
        task= new Task(enter->name(),enter->duration(),enter->getDevelopers(),enter->getDependences());
        model->tasks()->push_back(task);
        list3->addItem(task->toString());
    }
    delete enter;
}

void ThirdPage::editTask()
{
    if(list3->selectedItems().size()==1)
    {
        Task *task = model->tasks()->at(list3->currentRow());
        TaskEnter *dialog = new TaskEnter(task,model);
        int result = dialog->exec();
        if(result)
        {
           task->setName(dialog->name());
           task->setDuration(dialog->duration());
           task->developers()=dialog->getDevelopers();
           task->dependences()=dialog->getDependences();

           list3->currentItem()->setText(task->toString());
        }
        delete dialog;
    }
}
void ThirdPage::deleteTask()
{
    if(list3->selectedItems().size()==1)
    {
        int index = list3->currentRow();
        Task *task = model->tasks()->at(index);
        QListWidgetItem *item = list3->item(index);
        list3->removeItemWidget(item);
        delete item;

        model->tasks()->remove(index);
        delete task;
    }
}

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
        list3->addItem("zuzu");
    }
    delete enter;
}

void ThirdPage::editTask()
{

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

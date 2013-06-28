#include "secondpage.h"
#include "enterdeveloper.h"

SecondPage::SecondPage(Model *model,QWidget *parent) :
    QWidget(parent),
    model(model),
    list1(new QListWidget),
    mainlayout2(new QVBoxLayout),
    buttonslayout(new QHBoxLayout),
    adddeveloper(new QPushButton("add")),
    editdeveloper(new QPushButton("edit")),
    deletedeveloper(new QPushButton("delete"))

{
    setLayout(mainlayout2);
    mainlayout2->addWidget(list1);
    mainlayout2->addLayout(buttonslayout);
    buttonslayout->addWidget(adddeveloper);
    buttonslayout->addWidget(editdeveloper);
    buttonslayout->addWidget(deletedeveloper);


    QObject::connect(adddeveloper,SIGNAL(clicked()),this,SLOT(addDeveloper()));
    QObject::connect(editdeveloper,SIGNAL(clicked()),this,SLOT(editDeveloper()));
    QObject::connect(deletedeveloper,SIGNAL(clicked()),this,SLOT(deleteDeveloper()));
}
void SecondPage::addDeveloper()
{

    Developer *developer=0;
    Enterdeveloper *dialog = new Enterdeveloper(developer);
    int result = dialog->exec();
    if(result)
    {
       developer= new Developer(dialog->name());
       model->developers()->push_back(developer);
       list1->addItem(developer->name());
    }
    delete dialog;


}
void SecondPage::editDeveloper()
{
    if(list1->selectedItems().size()==1)
       {
           Developer *developer = model->developers()->at(list1->currentRow());
           Enterdeveloper *dialog = new Enterdeveloper(developer);
           int result = dialog->exec();
           if(result)
           {
              developer->setName(dialog->name());
              list1->currentItem()->setText(developer->name());
           }
           delete dialog;
       }
}

void SecondPage::deleteDeveloper()
{
    if(list1->selectedItems().size()==1)
    {
        int index = list1->currentRow();
        Developer *developer = model->developers()->at(index);
        QListWidgetItem *item = list1->item(index);
        list1->removeItemWidget(item);
        delete item;

        model->developers()->remove(index);
        delete developer;
    }
}

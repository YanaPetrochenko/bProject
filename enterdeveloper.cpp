#include "enterdeveloper.h"

Enterdeveloper::Enterdeveloper(Developer *developer,QWidget *parent) :
    QDialog(parent),

   lineEdit(new QLineEdit("Enter name of developer ")),
   mainLayout(new QVBoxLayout),
   buttonLayout(new QHBoxLayout),
   ok(new QPushButton("Ok")),
   cancel(new QPushButton("Cancel"))

{
    if(developer)
        lineEdit->setText(developer->name());
    else
        lineEdit->selectAll();

    setModal(true);//работа только с диалогом
    setLayout(mainLayout);
    mainLayout->addWidget(lineEdit);
    mainLayout->addLayout(buttonLayout);
    buttonLayout->addWidget(ok);
    buttonLayout->addWidget(cancel);

    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(cancel,SIGNAL(clicked()),this,SLOT(reject()));

}
QString Enterdeveloper:: name() const
{
    return (lineEdit->text());
}


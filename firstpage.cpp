#include "firstpage.h"
#include <QLabel>
//QLabel lable1("hello");
FirstPage::FirstPage(Model *model, QWidget *parent) :
    QWidget(parent),
   model(model),
   display1(new QLineEdit()),
   time(new QTimeEdit()),
   data(new QDateEdit()),
   timing(new QHBoxLayout()),
   then(new QPushButton("Apply")),
   //arrowright(new QPushButton("->")),
   mainLayout(new QVBoxLayout),
   buttonLayout(new QHBoxLayout),
   mapper(new QSignalMapper),
   nameproject(new QLabel("Name of a project")),
   timebeginning(new QLabel("Time of the beginning"))
{
    setLayout(mainLayout);
    mainLayout->addWidget(nameproject);
    mainLayout->addWidget(display1);
    //display1->colorCount();
    mainLayout->addWidget(timebeginning);
    mainLayout->addLayout(timing),
    timing->addWidget(time);
    timing->addWidget(data);
    data->setDate(QDate::currentDate());
    data->setDisplayFormat("dd MMMM yyyy");
    data->setCalendarPopup(true);
    time->setTime(QTime::currentTime());
    time->setDisplayFormat("hh:mm");
    mainLayout->addWidget(time);
    mainLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));
    mainLayout->addLayout(buttonLayout);
    buttonLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Expanding));

    buttonLayout->addWidget(then);
   // buttonLayout->addWidget(arrowright);

    QObject::connect(then,SIGNAL(clicked()),this,SLOT(apply()));


}

void FirstPage::apply()
{
    model->name()=display1->text();
    model->startDateTime()=QDateTime(data->date(),time->time());
}

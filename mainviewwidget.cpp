#include "mainviewwidget.h"

mainviewwidget::mainviewwidget(QWidget *parent) :
    QWidget(parent),
    model(new Model),
    tabwidget(new QTabWidget(this)),
    page1(new FirstPage(model)),
            page2(new SecondPage(model)),
            page3(new ThirdPage(model)),
            mainmainlayout(new QVBoxLayout),
            resultbutton(new QHBoxLayout),
            calculate(new QPushButton("Calculate"))

    {
        setLayout(mainmainlayout);
        mainmainlayout->addWidget(tabwidget);
       // tabwidget->setMinimumSize(350,350);
        tabwidget->addTab(page1,"&Project");
        tabwidget->addTab(page2,"&Developers");
        tabwidget->addTab(page3,"&Tasks");
        mainmainlayout->addLayout(resultbutton);
        resultbutton->addWidget(calculate);


        QObject::connect(calculate,SIGNAL(clicked()),this,SLOT(addresult()));
    }

mainviewwidget::~mainviewwidget()
{
   delete model;
}
void mainviewwidget::addresult()
{
    ResultWidget*result=new ResultWidget;
    int res = result->exec();
    delete result;

}


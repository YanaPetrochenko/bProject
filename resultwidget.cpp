#include "resultwidget.h"

ResultWidget::ResultWidget(Model *model, QWidget *parent) :
    QDialog(parent),
    model(model),
    mainlayout(new QVBoxLayout),
    nameofproject(new QLabel("The name of the project:\n"+model->name())),
    time(new QGroupBox("Time of the project")),
    criticaltime(new QGroupBox("Criticaltime of the project")),
    for_time(new QTextEdit),
    for_criticaltime(new QTextEdit),
    timetext(new QHBoxLayout),
    criticaltimetext(new QHBoxLayout)

{
    model->calculate();
    setLayout(mainlayout);
    mainlayout->addWidget(nameofproject);
    mainlayout->addWidget(time);
    mainlayout->addWidget(criticaltime);
    time->setLayout(timetext);
    timetext->addWidget(for_time);
    for_time->append(model->startDateTime().toString("dd MMMM hh:mm"));
    for_time->append(model->endDateTime().toString("dd MMMM hh:mm"));
    for_time->append("\nAll tasks:");
    for(int i=0;i<model->tasks()->size();++i)
    {
        for_time->append(model->tasks()->at(i)->toString());

    }
    criticaltime->setLayout(criticaltimetext);
    criticaltimetext->addWidget(for_criticaltime);
    if(model->root())
    {
        Task *current=model->root();
        while(current)
        {
            for_criticaltime->append(current->toString());
            current=model->criticalpath(current);
        }
    }


}

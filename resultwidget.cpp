#include "resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent) :
    QDialog(parent),
    mainlayout(new QVBoxLayout),
    nameofproject(new QLabel("The name of the project: ")),
    time(new QGroupBox("Time of the project")),
    criticaltime(new QGroupBox("Criticaltime of the project")),
    for_time(new QTextEdit),
    for_criticaltime(new QTextEdit),
    timetext(new QHBoxLayout),
    criticaltimetext(new QHBoxLayout)

{
    setLayout(mainlayout);
    mainlayout->addWidget(nameofproject);
    mainlayout->addWidget(time);
    mainlayout->addWidget(criticaltime);
    time->setLayout(timetext);
    criticaltime->setLayout(criticaltimetext);


}

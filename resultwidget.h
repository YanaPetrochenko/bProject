#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include <QtGui>
#include "model.h"


class ResultWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ResultWidget(Model *model,QWidget *parent = 0);
    
signals:
    
public slots:

private:
    Model *const model;
    QVBoxLayout*mainlayout;
    QLabel*nameofproject;
    QGroupBox*time;
    QGroupBox*criticaltime;
    QTextEdit*for_time;
    QTextEdit*for_criticaltime;
    QHBoxLayout*timetext;
    QHBoxLayout*criticaltimetext;

    
};

#endif // RESULTWIDGET_H

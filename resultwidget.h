#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include <QtGui>


class ResultWidget : public QDialog
{
    Q_OBJECT
public:
    explicit ResultWidget(QWidget *parent = 0);
    
signals:
    
public slots:

private:
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

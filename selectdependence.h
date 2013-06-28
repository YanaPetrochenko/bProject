#ifndef SELECTDEPENDENCE_H
#define SELECTDEPENDENCE_H

#include <QDialog>
#include <QtGui>
#include "task.h"

class SelectDependence : public QDialog
{
    Q_OBJECT
public:
    explicit SelectDependence(Task *current, QVector<Task *> *available, QWidget *parent = 0);
    ~SelectDependence();
    Task *selected();
signals:
    
public slots:
private slots:
    void confirm();
private:
    QPushButton*ok;
    QPushButton*cancel;
    QComboBox*combobox;
    QVBoxLayout*mainlayout;
    QHBoxLayout*buttonlayout;
    Task *current;
    QVector<Task *> *list;
    QVector<Task *> *available;

    
};

#endif // SELECTDEPENDENCE_H

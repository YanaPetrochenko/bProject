#ifndef ENTERDEVELOPER_H
#define ENTERDEVELOPER_H

#include <QDialog>
#include <QtGui>
#include "developer.h"
class Enterdeveloper : public QDialog
{
    Q_OBJECT
public:
    explicit Enterdeveloper(Developer *developer,QWidget *parent = 0);
    QString name() const;
    
signals:
    
public slots:
private:
    QVBoxLayout*mainLayout;
    QLineEdit*lineEdit;
    QHBoxLayout*buttonLayout;
    QPushButton*ok;
    QPushButton*cancel;
    
};

#endif // ENTERDEVELOPER_H

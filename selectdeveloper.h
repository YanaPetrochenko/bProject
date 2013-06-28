#ifndef SELECTDEVELOPER_H
#define SELECTDEVELOPER_H

#include <QDialog>

class SelectDeveloper : public QDialog
{
    Q_OBJECT
public:
    explicit SelectDeveloper(QWidget *parent = 0);
    
signals:
    
public slots:
private:
    QPushButton*ok;
    QPushButton*cancel;

    
};

#endif // SELECTDEVELOPER_H

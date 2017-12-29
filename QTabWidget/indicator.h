#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QLineEdit>
#include <QSpinBox>

class Indicator:public QWidget{
    Q_OBJECT
private:
    QSpinBox* spinBox;
    QLCDNumber* lcd;
public:
    Indicator(const QString& window_name="",int base=10,QWidget* parent=0);

};

#endif

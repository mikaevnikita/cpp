#include "indicator.h"

Indicator::Indicator(const QString &window_name, int base, QWidget *parent):QWidget(parent){
    setWindowTitle(window_name);
    QVBoxLayout* layout = new QVBoxLayout(this);
    spinBox = new QSpinBox;
    lcd = new QLCDNumber;
    spinBox->setRange(0,1000);

    switch(base){
    case 10:
        lcd->setDecMode();
        break;
    case 16:
        lcd->setHexMode();
        break;
    case 8:
        lcd->setOctMode();
        break;
    case 2:
        lcd->setBinMode();
        break;
    default:
        lcd->setDecMode();
        break;
    }

    QObject::connect(spinBox,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));

    layout->addWidget(lcd);
    layout->addWidget(spinBox);
    setLayout(layout);
}

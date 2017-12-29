#include "main_window.h"

SomeWidget::SomeWidget(QWidget *parent):QWidget(parent){
    le = new QLineEdit;
    pb = new QPushButton("Set");
    lb = new QLabel;

    hbl = new QHBoxLayout(this);
    hbl->addWidget(le);
    hbl->addWidget(pb);
    hbl->addWidget(lb);

    this->setLayout(hbl);

    QObject::connect(pb,SIGNAL(clicked(bool)),this,SLOT(changeLabel()));
}

void SomeWidget::changeLabel(){
    QString text = le->text();
    lb->setText(text);
    emit labelChanged(text);
}

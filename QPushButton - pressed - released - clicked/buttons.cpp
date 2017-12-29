#include <buttons.h>
#include <iostream>
Buttons::Buttons(const QString &window_name, QWidget *parent):QWidget(parent){
    setWindowTitle(window_name);
    pb = new QPushButton("Press me",this);
    original_palette = palette();
    QObject::connect(pb,SIGNAL(pressed()),this,SLOT(slotButtonPressed()));
    QObject::connect(pb,SIGNAL(released()),this,SLOT(slotButtonReleased()));
    QObject::connect(pb,SIGNAL(clicked(bool)),this,SLOT(slotButtonClicked()));
}


void Buttons::slotButtonPressed(){
    QPalette pal = palette();
    pal.setColor(backgroundRole(), QColor(Qt::blue));
    setPalette(pal);
    std::cout << "Pressed" << std::endl;
}

void Buttons::slotButtonReleased(){
    QPalette pal = original_palette;
    setPalette(pal);
    std::cout << "Released" << std::endl;
}

void Buttons::slotButtonClicked(){
    std::cout << "Clicked" << std::endl;
}

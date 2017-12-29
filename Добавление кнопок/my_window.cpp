#include <my_window.h>

MyWindow::MyWindow(const QString &new_window_name, QWidget *parent):QWidget(parent),window_name(new_window_name){
    setWindowTitle(window_name);
    main_layout=new QHBoxLayout;
    left_panel=new QVBoxLayout;
    right_panel=new QVBoxLayout;
    main_button=new QPushButton("ADD");
    left_panel->addWidget(main_button);
    main_layout->addLayout(left_panel);
    main_layout->addLayout(right_panel);
    setLayout(main_layout);
    connect(main_button,SIGNAL(clicked(bool)),this,SLOT(addNewButton()));
}

void MyWindow::addNewButton(){
    static int counter=0;
    QString button_name=QString("Button %1").arg(counter);
    QPushButton* new_button=new QPushButton(button_name);
    right_panel->addWidget(new_button);
    connect(new_button,SIGNAL(clicked(bool)),this,SLOT(removeButton()));
    counter++;
}

void MyWindow::removeButton(){
    QPushButton* btn=qobject_cast<QPushButton*>(sender());
    right_panel->removeWidget(btn);
    btn->deleteLater();
}

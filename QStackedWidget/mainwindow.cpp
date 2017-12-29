#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    some_widget = new SomeWidget(this);
    setCentralWidget(some_widget);
}

SomeWidget::SomeWidget(QWidget *parent){
    stacked_widget = new QStackedWidget(this);
    pb = new QPushButton("Change widget",this);
    main_layout = new QVBoxLayout(this);

    main_layout->addWidget(stacked_widget);
    main_layout->addWidget(pb);


    lbl1 = new QLabel("Widget1");
    lbl2 = new QLabel("Widget2");

    stacked_widget->addWidget(lbl1);
    stacked_widget->addWidget(lbl2);

    stacked_widget->setCurrentWidget(lbl1);

    this->setLayout(main_layout);

    QObject::connect(pb,SIGNAL(clicked(bool)),this,SLOT(slotChangeWidget()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void SomeWidget::slotChangeWidget(){
    if(stacked_widget->currentWidget() == lbl1)
        stacked_widget->setCurrentWidget(lbl2);
    else
        stacked_widget->setCurrentWidget(lbl1);
}

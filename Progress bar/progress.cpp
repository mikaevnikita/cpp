#include <progress.h>

Progress::Progress(const QString& window_name, QWidget *parent):QWidget(parent),current_step(0){
    setWindowTitle(window_name);

    bar=new QProgressBar;
    bar->setRange(0,5);
    bar->setMinimumWidth(200);
    bar->setAlignment(Qt::AlignCenter);

    QPushButton* nextStepButton = new QPushButton("&Next Step");
    QPushButton* resetButton = new QPushButton("&Reset");

    QObject::connect(nextStepButton,SIGNAL(clicked(bool)),this,SLOT(slotNextStep()));
    QObject::connect(resetButton,SIGNAL(clicked(bool)),this,SLOT(slotReset()));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(bar);
    layout->addWidget(nextStepButton);
    layout->addWidget(resetButton);

    this->setLayout(layout);
}

void Progress::slotNextStep(){
    bar->setValue(++current_step);
}

void Progress::slotReset(){
    current_step=0;
    bar->reset();
}

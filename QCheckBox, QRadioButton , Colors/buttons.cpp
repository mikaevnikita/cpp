#include <buttons.h>

Buttons::Buttons(const QString &window_name, QWidget *parent):QGroupBox(window_name,parent){
    resize(500,500);
    setCheckable(true);
    setChecked(true);

    red_radio_button = new QRadioButton("Red");
    green_radio_button = new QRadioButton("Gren");
    blue_radio_button = new QRadioButton("Blue");

    QObject::connect(red_radio_button,SIGNAL(clicked(bool)),this,SLOT(slotRadioButtonClicked()));
    QObject::connect(green_radio_button,SIGNAL(clicked(bool)),this,SLOT(slotRadioButtonClicked()));
    QObject::connect(blue_radio_button,SIGNAL(clicked(bool)),this,SLOT(slotRadioButtonClicked()));

    light_check_box = new QCheckBox("Light");
    QObject::connect(light_check_box,SIGNAL(clicked()),this,SLOT(slotRadioButtonClicked()));

    exit_button = new QPushButton("Exit");
    QObject::connect(exit_button,SIGNAL(clicked(bool)),this,SLOT(close()));

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(red_radio_button);
    layout->addWidget(green_radio_button);
    layout->addWidget(blue_radio_button);
    layout->addWidget(light_check_box);
    layout->addWidget(exit_button);
    setLayout(layout);
}


void Buttons::slotRadioButtonClicked(){
    QPalette pal = palette();
    int nLight = light_check_box->isChecked() ? 150 : 80;
    if(red_radio_button->isChecked()) {
        pal.setColor(backgroundRole(), QColor(Qt::red).light(nLight));
    }
    else if(green_radio_button->isChecked()) {
        pal.setColor(backgroundRole(), QColor(Qt::green).light(nLight));
    }
    else {
        pal.setColor(backgroundRole(), QColor(Qt::blue).light(nLight));
    }
    setPalette(pal);
}

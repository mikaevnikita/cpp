#include "indicator.h"
#include <QApplication>

int main(int argv,char** argc){
    QApplication app(argv,argc);
    QWidget main_window;
    QVBoxLayout* layout = new QVBoxLayout(&main_window);

    Indicator* indicator1 = new Indicator("",10,0);
    Indicator* indicator2 = new Indicator("",16,0);
    Indicator* indicator3 = new Indicator("",2,0);

    layout->addWidget(indicator1);
    layout->addWidget(indicator2);
    layout->addWidget(indicator3);

    main_window.setLayout(layout);
    main_window.setWindowTitle("Indicators");
    main_window.show();
    return app.exec();
}

#include "main_window.h"
#include <QApplication>

int main(int argv,char** argc){
    QApplication app(argv,argc);
    QWidget main_window;
    QVBoxLayout* layout = new QVBoxLayout;
    SomeWidget* widget1 = new SomeWidget;
    SomeWidget* widget2 = new SomeWidget;
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    main_window.setLayout(layout);
    main_window.show();
    return app.exec();
}

#include <QApplication>
#include "my_window.h"

int main(int argv, char** argc){
    QApplication app(argv,argc);
    MyWindow window("MessageBox");
    window.show();
    return app.exec();
}

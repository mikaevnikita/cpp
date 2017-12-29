#include <QtWidgets>
#include <buttons.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Buttons b;
    b.show();
    return app.exec();
}

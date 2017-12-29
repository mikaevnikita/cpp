#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QMenu>
using namespace Qt;

int main(int argc, char** argv){
    QApplication app(argc,argv);
    QWidget window;
    QPushButton* pb = new QPushButton("Menu",&window);
    QPixmap pix(":/prefix1/rock");
    pb->setIcon(pix);
    QMenu* menu = new QMenu(pb);
    menu->addAction("Item1");
    menu->addAction("Item2");
    menu->addAction("Quit",&app,SLOT(quit()));
    pb->setMenu(menu);
    window.show();
    return app.exec();
}

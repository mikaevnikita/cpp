#include <QWidget>
#include <QApplication>
using namespace std;


int main(int argv,char** argc){
    QApplication app(argv,argc);
    QWidget wgt;
    wgt.setWindowTitle("My Window");
    QWidget* pwgt1 = new QWidget(&wgt);//Передаю родительский виджет
    QPalette pall_1;
    pall_1.setColor(pwgt1->backgroundRole(),Qt::blue);
    pwgt1->setPalette(pall_1);
    pwgt1->resize(100,100);
    pwgt1->move(25,25);
    pwgt1->setAutoFillBackground(true);

    QWidget* pwgt2 = new QWidget(&wgt);
    QPalette pall_2;
    pall_2.setBrush(pwgt2->backgroundRole(),QBrush(QPixmap(":/prefix1/rock")));
    pwgt2->setPalette(pall_2);
    pwgt2->resize(100,100);
    pwgt2->move(75,75);
    pwgt2->setAutoFillBackground(true);

    wgt.resize(200,200);
    wgt.show();
    return app.exec();
}


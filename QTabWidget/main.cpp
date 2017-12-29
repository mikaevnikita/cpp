#include <QtWidgets>
#include <indicator.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTabWidget   tab;
    QStringList  lst;

    lst << "Base 10" << "Base 16" << "Base 2" << "Base 8";
    QList<int> bases;
    bases.append(10);
    bases.append(16);
    bases.append(2);
    bases.append(8);

    QMutableListIterator<int> iter(bases);

    foreach(QString str, lst) {
        tab.addTab(new Indicator("",iter.next(), &tab), str);
    }

    tab.resize(360, 100);
    tab.show();

    return app.exec();
}

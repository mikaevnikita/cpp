#include <QApplication>
#include "progress.h"
using namespace Qt;

int main(int argc, char** argv){
    QApplication app(argc,argv);
    Progress progress_window("Progress bar example");
    progress_window.show();
    return app.exec();
}

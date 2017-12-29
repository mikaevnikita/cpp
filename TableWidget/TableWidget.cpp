#include <QtWidgets>

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    const int n=4;
    QTableWidget table(n,n);
    QStringList h_lst;
    QStringList v_lst;
    h_lst << "H First" << "H Second" << "H Third" << "H Four";
    v_lst << "V First" << "V Second" << "V Third" << "V Four";
    table.setHorizontalHeaderLabels(h_lst);
    table.setVerticalHeaderLabels(v_lst);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString("%1%2").arg(i).arg(j));
            table.setItem(i,j,item);
        }
    }
    table.show();
    return app.exec();
}

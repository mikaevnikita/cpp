#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}


class SomeWidget:public QWidget{
    Q_OBJECT
private:
    QStackedWidget* stacked_widget;
    QPushButton* pb;
    QVBoxLayout* main_layout;
    QLabel* lbl1;
    QLabel* lbl2;
public:
    SomeWidget(QWidget* parent = 0);
public slots:
    void slotChangeWidget();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    SomeWidget* some_widget;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

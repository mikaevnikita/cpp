#ifndef MY_WINDOW_H
#define MY_WINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MyWindow:public QWidget{
    Q_OBJECT
private:
    QString window_name;
    QHBoxLayout* main_layout;
    QVBoxLayout* left_panel;
    QVBoxLayout* right_panel;
    QPushButton* main_button;
public:
    MyWindow(const QString& new_window_name,QWidget* parent = nullptr);
private slots:
    void addNewButton();
    void removeButton();
};

#endif // MY_WINDOW_H

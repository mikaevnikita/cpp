#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class SomeWidget:public QWidget{
    Q_OBJECT
private:
    QLineEdit* le;
    QPushButton* pb;
    QLabel* lb;
    QHBoxLayout* hbl;
public:
    SomeWidget(QWidget* parent = 0);
public slots:
    void changeLabel();
signals:
    void labelChanged(const QString& text);
};

#endif

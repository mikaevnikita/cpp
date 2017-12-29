#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Buttons:public QWidget{
    Q_OBJECT
private:
    QPushButton* pb;
    QPalette original_palette;
public:
    Buttons(const QString& window_name = "", QWidget* parent = 0);
public slots:
    void slotButtonPressed();
    void slotButtonReleased();
    void slotButtonClicked();
};



#endif // BUTTONS_H

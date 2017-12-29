#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Buttons:public QGroupBox{
    Q_OBJECT
private:
    QCheckBox* light_check_box;
    QRadioButton* red_radio_button;
    QRadioButton* green_radio_button;
    QRadioButton* blue_radio_button;
    QPushButton* exit_button;
public:
    Buttons(const QString& window_name = "", QWidget* parent = 0);
public slots:
    void slotRadioButtonClicked();
};



#endif // BUTTONS_H

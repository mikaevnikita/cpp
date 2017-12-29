#ifndef PROGRESS_H
#define PROGRESS_H
#include <QProgressBar>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class Progress:public QWidget{
    Q_OBJECT
private:
    QProgressBar* bar;
    int current_step;
public:
    Progress(const QString& window_name="",QWidget* parent=0);
public slots:
    void slotNextStep();
    void slotReset();
};

#endif

#ifndef HEADWINDOW_H
#define HEADWINDOW_H

#include <QWidget>

namespace Ui {
class Headwindow;
}

class Headwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Headwindow(QWidget *parent = 0);
    ~Headwindow();
    QTimer *mytimer;
    void switchPage();
public slots:
    void Getdatetime();
private:
    Ui::Headwindow *ui;
};

#endif // HEADWINDOW_H

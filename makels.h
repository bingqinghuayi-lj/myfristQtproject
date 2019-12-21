#ifndef MAKELS_H
#define MAKELS_H

#include <QWidget>

namespace Ui {
class Makels;
}

class Makels : public QWidget
{
    Q_OBJECT
QTimer *mytimer;
public:
    explicit Makels(QWidget *parent = 0);
    ~Makels();
public slots:
    void Getdatetime();
private:
    Ui::Makels *ui;
};

#endif // MAKELS_H

#ifndef HAHAHA_H
#define HAHAHA_H

#include <QWidget>

namespace Ui {
class Hahaha;
}

class Hahaha : public QWidget
{
    Q_OBJECT

public:
    explicit Hahaha(QWidget *parent = 0);
    ~Hahaha();
signals:
    void mysignal1();
    void mysignal2();
private:
    Ui::Hahaha *ui;
};

#endif // HAHAHA_H

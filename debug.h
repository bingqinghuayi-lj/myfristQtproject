#ifndef DEBUG_H
#define DEBUG_H

#include <QMainWindow>

namespace Ui {
class Debug;
}

class Debug : public QMainWindow
{
    Q_OBJECT

public:
    explicit Debug(QWidget *parent = 0);
    ~Debug();

private:
    Ui::Debug *ui;
};

#endif // DEBUG_H

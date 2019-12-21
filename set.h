#ifndef SET_H
#define SET_H

#include <QWidget>

namespace Ui {
class Set;
}

class Set : public QWidget
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = 0);
    ~Set();
    QTimer *mytimer;
    void switchPage();
signals:
    void mysignal();//返回首页
    void mysignal2();//返回设置
public slots:
    void Getdatetime();
private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button4_clicked();

private:
    Ui::Set *ui;
};

#endif // SET_H

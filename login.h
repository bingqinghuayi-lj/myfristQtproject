#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>



class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);
    int login(char *buf_user,char *buf_paswrd);
    int regist(char *buf_user,char *buf_paswrd);

signals:

public slots:
};

#endif // LOGIN_H

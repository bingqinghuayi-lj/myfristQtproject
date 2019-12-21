#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "register.h"
#include <QPushButton>
#include <QPixmap>
#include "headwindow.h"
#include <QSize>
#include <QIcon>
#include "login.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //新建一个主窗口
    Headwindow *headwindow = new Headwindow;
    ui->setupUi(this);
    //背景图片
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/image/bug1.jpeg")));
    setPalette(pal);
    //注册.创建注册窗口
    Register *registers = new Register;


    //返回主页
    connect(registers,&Register::mysigner,[=]{
        registers->hide();
        this->show();
    });
    //进入注册窗口
    connect(ui->buttonregister,&QPushButton::clicked,[=]{
        this->hide();
        registers->show();
    });
    //登录
    connect(ui->buttonlig,&QPushButton::clicked,[=]
    {
        FILE *fp;
        if ((fp = fopen("C:/Users/28903/Desktop/a.txt","r+")) == NULL)
        {
            perror("fail to fopen");
            return;
        }
        fseek(fp, 0, SEEK_END);
        long int len = ftell(fp);
        char *lrc = (char *)malloc(len + 1);
        fseek(fp, 0, SEEK_SET);
        fread(lrc, len, 1, fp);
        char *str[256] = {NULL};
        int i = 0;
        str[i] = strtok(lrc, "\n");
        while (str[i] != NULL)
        {
            i++;
            str[i] = strtok(NULL, "\n");
        }
        fclose(fp);

        QString s1=ui->lineedituesr->text();
        char* sss;
        QByteArray ba1=s1.toLatin1();
        sss=ba1.data();

        QString s2=ui->lineeditpasswd->text();
        char* sss_1;
        QByteArray ba2=s2.toLatin1();
        sss_1=ba2.data();

        char *p=NULL;
        char *pp=NULL;
        char *p1=NULL;
        for(int j=0;j<i;j++)
        {
            pp=NULL;
            p1=new char[strlen(str[j])+1];
            p=p1;
            strcpy(p1,str[j]);
            while(*p!=':')
            {
                p++;
            }p++;
            pp=strtok(str[j],":");
            //delete p1;

            if(qstrcmp(sss,pp)==0)
            {
                if(qstrcmp(sss_1,p)==0)
                {
                    QMessageBox::information(this, "正确", "登录成功");
                    headwindow->show();
                    this->hide();
                    delete p1;
                    return ;
                }

            }


        }


        QMessageBox::critical(this, "错误", "您输入有误，请重新输入");

        delete p1;
    });
    //退出
    connect(ui->buttonquit,&QPushButton::clicked,this,&MainWindow::close);

    //清空
    connect(ui->buttonclear,&QPushButton::clicked,[=]
    {
        ui->lineedituesr->clear();
        ui->lineeditpasswd->clear();
    });

    //给按钮添加图片
    QIcon button_lig(":/image/login.png");
    ui->buttonlig->setMinimumSize(60,60);
    ui->buttonlig->setMaximumSize(60,60);
    ui->buttonlig->setIcon(button_lig);
    ui->buttonlig->setIconSize(QSize(60,60));

    QIcon button_register(":/image/add.png");
    ui->buttonregister->setMinimumSize(60,60);
    ui->buttonregister->setMaximumSize(60,60);
    ui->buttonregister->setIcon(button_register);
    ui->buttonregister->setIconSize(QSize(60,60));

    QIcon button_clear(":/image/clear.jpg");
    ui->buttonclear->setMinimumSize(50,50);
    ui->buttonclear->setMaximumSize(50,50);
    ui->buttonclear->setIcon(button_clear);
    ui->buttonclear->setIconSize(QSize(60,60));

    QIcon button_quit(":/image/quit.jpg");
    ui->buttonquit->setMinimumSize(60,60);
    ui->buttonquit->setMaximumSize(60,60);
    ui->buttonquit->setIcon(button_quit);
    ui->buttonquit->setIconSize(QSize(60,60));
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "set.h"
#include "ui_set.h"
#include <QSize>
#include <QPushButton>
#include <QPixmap>
#include <QDateTime>
#include <iostream>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include "hahaha.h"
#include "debug.h"
Set::Set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set)
{
    this->setFixedSize(1200,800);
    ui->setupUi(this);
    //显示时间和日期
    mytimer = new QTimer(this);
    mytimer->start(1000);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(Getdatetime()));

    //退出
    connect(ui->buttonquit,&QPushButton::clicked,this,&Set::close);

    //给按钮添加图片
    QIcon button_home(":/image/OnePiece");
    ui->buttonhead->setMinimumSize(60,60);
    ui->buttonhead->setMaximumSize(60,60);
    ui->buttonhead->setIcon(button_home);
    ui->buttonhead->setIconSize(QSize(60,60));

    QIcon button_set1(":/image/set1.png");
    ui->buttonset->setMinimumSize(60,60);
    ui->buttonset->setMaximumSize(60,60);
    ui->buttonset->setIcon(button_set1);
    ui->buttonset->setIconSize(QSize(60,60));

    QIcon button_read(":/image/set.png");
    ui->buttonread->setMinimumSize(60,60);
    ui->buttonread->setMinimumSize(60,60);
    ui->buttonread->setIcon(button_read);
    ui->buttonread->setIconSize(QSize(60,60));

    QIcon button_get(":/image/set3.jpg");
    ui->buttonget->setMinimumSize(60,60);
    ui->buttonget->setMaximumSize(60,60);
    ui->buttonget->setIcon(button_get);
    ui->buttonget->setIconSize(QSize(60,60));

    QIcon button_word(":/image/New.png");
    ui->buttonword->setMinimumSize(60,60);
    ui->buttonword->setMaximumSize(60,60);
    ui->buttonword->setIcon(button_word);
    ui->buttonword->setIconSize(QSize(60,60));

    QIcon button_quit(":/image/quit.jpg");
    ui->buttonquit->setMinimumSize(60,60);
    ui->buttonquit->setMaximumSize(60,60);
    ui->buttonquit->setIcon(button_quit);
    ui->buttonquit->setIconSize(QSize(50,50));

}

Set::~Set()
{
    delete ui;
}

void Set::Getdatetime()
{
    QTime timeNow = QTime::currentTime();
    ui->label1->setText(tr("时间:%1").arg(timeNow.toString()));
    ui->label2->setText(tr("日期:")+(QDate::currentDate().toString(tr("yyyy年MM月dd日 ddd" ))));
}


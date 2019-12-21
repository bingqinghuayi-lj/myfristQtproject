#include "headwindow.h"
#include "ui_headwindow.h"
#include <QIcon>
#include <QSize>
#include <QPushButton>
#include <QPixmap>
#include <QDateTime>
#include <iostream>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include "set.h"
#include "hahaha.h"
#include <QMouseEvent>
#include "debug.h"
#include <vector>
#include <QMessageBox>
using namespace std;
int i = 0;
Headwindow::Headwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Headwindow)
{
    this->setFixedSize(1200,800);
    ui->setupUi(this);
    //显示时间和日期
    mytimer = new QTimer(this);
    mytimer->start(1000);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(Getdatetime()));
    //增加数据
    connect(ui->buttonadd,&QPushButton::clicked,[=]()
    {
        vector<int> v;
        v.push_back(10);
        QMessageBox::information(this,"增加","已成功添加");
    });
    //删除数据
    connect(ui->buttondelete,&QPushButton::clicked,[=]
    {
        vector<int> v;
        v.push_back(10);
        QMessageBox::information(this,"删除","已成功删除");
    });
    //查询数据
    connect(ui->buttonfind,&QPushButton::clicked,[=]
    {
        //vector<int> v;

        QMessageBox::information(this,"查找","未查到");
    });
    //退出
    connect(ui->buttonquit,&QPushButton::clicked,this,&Headwindow::close);

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
    //将各个窗口建立联系
    connect(ui->buttonhead,&QPushButton::clicked,this,&Headwindow::switchPage);
    connect(ui->buttonset,&QPushButton::clicked,this,&Headwindow::switchPage);
    connect(ui->buttonread,&QPushButton::clicked,this,&Headwindow::switchPage);
    connect(ui->button1,&QPushButton::clicked,this,&Headwindow::switchPage);
    connect(ui->button2,&QPushButton::clicked,this,&Headwindow::switchPage);

    Debug *debug = new Debug;
    connect(ui->button4,&QPushButton::clicked,[=]
    {
        debug->show();
    });
    //表格拉伸
    ui->tableWidget->setColumnCount(2);//设置列
    ui->tableWidget->setRowCount(70);//设置行

    QStringList header;  //QString类型的List容器

    header<<"操作类型"<<"操作时间";//设置内容是
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setFixedHeight(20);
    ui->tableWidget->horizontalHeader()->resizeSection(0,220);
    ui->tableWidget->horizontalHeader()->resizeSection(1,220);
    //内容剧中
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //操作记录和时间
    connect(ui->button1,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText(ui->button1->text());

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));

        i++;
    });
    connect(ui->button2,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText(ui->button2->text());

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->button3,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText(ui->button3->text());

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->button4,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText(ui->button4->text());

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonhead,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("主页");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonset,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("设置");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonread,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("哈哈");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonget,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("啥也没有哦");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;

    });
    connect(ui->buttonword,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("这也没有哦");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonquit,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("退出");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonadd,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("增加");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttonfind,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("查询");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
    connect(ui->buttondelete,&QPushButton::clicked,[=](){

        QTableWidgetItem *name=new QTableWidgetItem();//创建一个Item
        //设置内容
        name->setText("删除");

        ui->tableWidget->setItem(i, 0,name);
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str_time));
        i++;
    });
}

Headwindow::~Headwindow()
{
    delete ui;
}

void Headwindow::switchPage()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button==ui->buttonhead)
        ui->stackedWidget->setCurrentIndex(0);
    if(button==ui->buttonset)
        ui->stackedWidget->setCurrentIndex(1);
    if(button==ui->buttonread)
        ui->stackedWidget->setCurrentIndex(2);
    if(button==ui->button1)
        ui->stackedWidget_2->setCurrentIndex(0);
    if(button==ui->button2)
        ui->stackedWidget_2->setCurrentIndex(1);
}

void Headwindow::Getdatetime()
{
    QTime timeNow = QTime::currentTime();
    ui->label1->setText(tr("时间:%1").arg(timeNow.toString()));
    ui->label2->setText(tr("日期:")+(QDate::currentDate().toString(tr("yyyy年MM月dd日 ddd" ))));
    ui->label11->setText(tr("时间:%1").arg(timeNow.toString()));
    ui->label11_1->setText(tr("日期:")+(QDate::currentDate().toString(tr("yyyy年MM月dd日 ddd" ))));
}

#include "debug.h"
#include "ui_debug.h"
#include <QMenuBar> //菜单栏
#include <QMenu> //菜单
#include <QAction> //菜单项
#include <QDebug>
#include <QPixmap> //图片空间
#include <QToolBar> //工具栏
#include <QStatusBar> //状态栏
#include <QLabel>
#include <QPushButton>
#include <QDockWidget>  //铆接部件
#include <QTextEdit> //文本编辑器
Debug::Debug(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Debug)
{
    ui->setupUi(this);

    QMenuBar *menu_bar = new QMenuBar(this);
    this->setMenuBar(menu_bar);

    //创建菜单
    QMenu *menu1 = new QMenu("操作(C)", this);
    menu_bar->addMenu(menu1);
    QMenu *menu2 = new QMenu("关于(A)", this);
    menu_bar->addMenu(menu2);


    QAction *act1 = new QAction("添加串口", this);
    menu1->addAction(act1);

    menu1->addSeparator();
    QAction *act2 = new QAction("打开串口", this);
    menu1->addAction(act2);
    QAction *act3 = new QAction("关闭串口", this);
    menu1->addAction(act3);
    //添加分割线
    menu1->addSeparator();

    QAction *act4 = new QAction("保存数据", this);
    menu1->addAction(act4);
    QAction *act5 = new QAction("读取文件", this);
    menu1->addAction(act5);
    QAction *act6 = new QAction("写入文件", this);
    menu1->addAction(act6);
    menu1->addSeparator();
    QAction *act7 = new QAction("读取间隔", this);
    menu1->addAction(act7);
    QAction *act8 = new QAction("计数清零", this);
    menu1->addAction(act8);
    menu1->addSeparator();
    QAction *act9 = new QAction("清空串口", this);
    menu1->addAction(act9);
    QAction *act10 = new QAction("退出程序", this);
    menu1->addAction(act10);

    QAction *act11 = new QAction("关于Lincom", this);
    menu2->addAction(act11);

    //工具栏
    QAction *act_tool4 = new QAction;
    ui->toolBar->addAction(act_tool4);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_4;
    pix_3_tool_4.load(":/image/open.png");
    act_tool4->setIcon(QIcon(pix_3_tool_4));

    QAction *act_tool1 = new QAction;
    ui->toolBar->addAction(act_tool1);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_1;
    pix_3_tool_1.load(":/image/add.png");
    act_tool1->setIcon(QIcon(pix_3_tool_1));

    QAction *act_tool2 = new QAction;
    ui->toolBar->addAction(act_tool2);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_2;
    pix_3_tool_2.load(":/image/stop.png");
    act_tool2->setIcon(QIcon(pix_3_tool_2));

    QAction *act_tool3 = new QAction;
    ui->toolBar->addAction(act_tool3);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_3;
    pix_3_tool_3.load(":/image/time.png");
    act_tool3->setIcon(QIcon(pix_3_tool_3));

    QAction *act_tool5 = new QAction;
    ui->toolBar->addAction(act_tool5);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_5;
    pix_3_tool_5.load(":/image/Luffy.png");
    act_tool5->setIcon(QIcon(pix_3_tool_5));

    QAction *act_tool6 = new QAction;
    ui->toolBar->addAction(act_tool6);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_6;
    pix_3_tool_6.load(":/imageve.png");
    act_tool6->setIcon(QIcon(pix_3_tool_6));

    QAction *act_tool7 = new QAction;
    ui->toolBar->addAction(act_tool7);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_7;
    pix_3_tool_7.load(":/image/cleanport.png");
    act_tool7->setIcon(QIcon(pix_3_tool_7));

    QAction *act_tool8 = new QAction;
    ui->toolBar->addAction(act_tool8);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_8;
    pix_3_tool_8.load(":/image/down.png");
    act_tool8->setIcon(QIcon(pix_3_tool_8));

    QAction *act_tool9 = new QAction;
    ui->toolBar->addAction(act_tool9);
    ui->toolBar->addSeparator();
    QPixmap pix_3_tool_9;
    pix_3_tool_9.load(":/image/Left.png");
    act_tool9->setIcon(QIcon(pix_3_tool_9));

}

Debug::~Debug()
{
    delete ui;
}

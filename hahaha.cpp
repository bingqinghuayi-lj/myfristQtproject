#include "hahaha.h"
#include "ui_hahaha.h"
#include "set.h"
Hahaha::Hahaha(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hahaha)
{
    ui->setupUi(this);
    this->setFixedSize(1200,800);

    //设置按钮图片
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

Hahaha::~Hahaha()
{
    delete ui;
}

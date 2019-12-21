#include "makels.h"
#include "ui_makels.h"
#include <QTimer>
#include <QStringList>
#include <QTableWidgetItem>
Makels::Makels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Makels)
{
    ui->setupUi(this);

}

Makels::~Makels()
{
    delete ui;
}


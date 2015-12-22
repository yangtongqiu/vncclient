#include "vnc_connecttion.h"
#include "ui_vnc_connecttion.h"

vnc_connecttion::vnc_connecttion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vnc_connecttion)
{
    ui->setupUi(this);
}

vnc_connecttion::~vnc_connecttion()
{
    delete ui;
}

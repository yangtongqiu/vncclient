#include "vnc_connecttion.h"
#include "ui_vnc_connecttion.h"
#include "vncclientwidget2cls.h"
#include "vncclientwidgetcls.h"

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

void vnc_connecttion::on_lineEdit_host_textChanged(const QString &arg1)
{
    QString host_add=ui->lineEdit_host->text();
}

void vnc_connecttion::on_lineEdit_port_textChanged(const QString &arg1)
{
     QString port_num=ui->lineEdit_port->text();
}



void vnc_connecttion::on_OK_button_clicked()
{
    QString host_add=ui->lineEdit_host->text();
    QString port_num=ui->lineEdit_port->text();
    int portnum=port_num.toInt();
    vncclientwidget2cls vnc;
        vnc.show();
        vnc.connectVNCTCP(host_add, portnum); // connect via TCP
    //vnc.connectVNCIPC("/var/nemd3/nemd3vnc"); connect via UNIX socket

}

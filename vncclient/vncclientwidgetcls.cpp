#include "vncclientwidgetcls.h"

vncClientWidgetCls::vncClientWidgetCls(QWidget *parent) :
    QWidget(parent)
{
    QPalette pl;
    pl.setColor(QPalette::Background,Qt::black);
    this->setPalette(pl);

    this->widgetResizing = false;

    this->vncFrame = new QFrame(this);
    this->vncFrame->move(10,10);
    this->vncFrame->resize(200,200);

    this->rfbWidget = new rfbclientwidgetcls(this->vncFrame);
    connect(this->rfbWidget,SIGNAL(vncFrameResizeSignal()),this,SLOT(vncFrameResizeSlot()));
    connect(this->rfbWidget,SIGNAL(vncFrameGetFocusSignal()),this,SLOT(vncFrameGetFocusSlot()));
    this->rfbWidget->move(0,0);
    this->rfbWidget->show();




    this->TSB = new QScrollBar(Qt::Horizontal,this);
    this->BSB = new QScrollBar(Qt::Horizontal,this);
    this->LSB = new QScrollBar(Qt::Vertical,this);
    this->RSB = new QScrollBar(Qt::Vertical,this);

    connect(this->TSB,SIGNAL(valueChanged(int)),this,SLOT(tsbValueChange(int)));
    connect(this->BSB,SIGNAL(valueChanged(int)),this,SLOT(bsbValueChange(int)));
    connect(this->RSB,SIGNAL(valueChanged(int)),this,SLOT(rsbValueChange(int)));
    connect(this->LSB,SIGNAL(valueChanged(int)),this,SLOT(lsbValueChange(int)));

    this->TSB->setVisible(false);
    this->BSB->setVisible(false);
    this->LSB->setVisible(false);
    this->RSB->setVisible(false);

    this->TSB->setMinimum(0);
    this->TSB->setValue(0);
    this->BSB->setMinimum(0);
    this->BSB->setValue(0);
    this->LSB->setMinimum(0);
    this->LSB->setValue(0);
    this->RSB->setMinimum(0);
    this->RSB->setValue(0);


    this->setMaximumSize(this->rfbWidget->geometry().width()+20,this->rfbWidget->geometry().height()+20);
    this->resize(660,500);
}

void vncClientWidgetCls::closeEvent(QCloseEvent *)
{
    this->rfbWidget->close();
    delete this->rfbWidget;
}

bool vncClientWidgetCls::connectVNCIPC(QString server)
{
    return this->rfbWidget->connectVNCIPC(server);
}

bool vncClientWidgetCls::connectVNCTCP(QString server, qint16 port)
{
    return this->rfbWidget->connectVNCTCP(server,port);
}

void vncClientWidgetCls::disconnectVNC()
{
    this->rfbWidget->disconnectVNC();
}

void vncClientWidgetCls::resizeEvent(QResizeEvent *)
{

    this->widgetResizing = true;

    this->TSB->setVisible(0);
    this->BSB->setVisible(0);
    this->LSB->setVisible(0);
    this->RSB->setVisible(0);

    //this->setMaximumSize(this->rfbWidget->width()+20,this->rfbWidget->height()+20);
    this->vncFrame->resize(this->geometry().width() - 20,this->geometry().height()-20);
    this->vncFrame->move(10,10);
    this->rfbWidget->move(0,0);

    this->TSB->resize(this->geometry().width() - 20,10);
    this->TSB->move(10,0);
    this->TSB->setMaximum(this->rfbWidget->geometry().width() - this->vncFrame->geometry().width());
    this->TSB->setMinimum(0);
    this->TSB->setValue(0);

    this->BSB->resize(this->geometry().width() - 20,10);
    this->BSB->move(10,this->geometry().height()-10);
    this->BSB->setMaximum(this->rfbWidget->geometry().width() - this->vncFrame->geometry().width());
    this->BSB->setMinimum(0);
    this->BSB->setValue(0);

    this->LSB->resize(10,this->geometry().height() -20);
    this->LSB->move(0,10);
    this->LSB->setMaximum(this->rfbWidget->geometry().height()- this->vncFrame->geometry().height());
    this->LSB->setMinimum(0);
    this->LSB->setValue(0);

    this->RSB->resize(10,this->geometry().height() -20);
    this->RSB->move(this->geometry().width()-10,10);
    this->RSB->setMaximum(this->rfbWidget->geometry().height()- this->vncFrame->geometry().height());
    this->RSB->setMinimum(0);
    this->RSB->setValue(0);

    if ((this->geometry().width() -20) < this->rfbWidget->geometry().width())
    {
        this->TSB->setVisible(true);
        this->BSB->setVisible(true);
    }

    if ((this->geometry().height()-20) < this->rfbWidget->geometry().height())
    {
        this->LSB->setVisible(true);
        this->RSB->setVisible(true);
    }

    this->widgetResizing = false;

    /*this->VSB->resize(10,this->geometry().height()-20);
    this->VSB->setMinimum(0);
    this->VSB->setMaximum(this->rfbWidget->geometry().height());
    this->VSB->move(this->geometry().width()-20,0);

    this->HSB->resize(this->geometry().width()-20,10);
    this->HSB->setMinimum(0);
    this->HSB->setMaximum(this->rfbWidget->width());
    this->HSB->move(0,this->geometry().height()-20);*/

   /*
    //make rfb widget at center
    this->setMinimumSize(this->rfbWidget->width()+40,this->rfbWidget->height()+40);
    qint32 mX = this->geometry().width() /2;
    qint32 mY = this->geometry().height()/2;


    qint32 rw = this->rfbWidget->geometry().width()/2;
    qint32 rh = this->rfbWidget->geometry().height()/2;


    qint32 tgtX = mX - rw;
    qint32 tgtY = mY - rh;


    this->rfbWidget->move(tgtX,tgtY);*/

}

void vncClientWidgetCls::leaveEvent(QEvent *)
{

}

void vncClientWidgetCls::vncFrameGetFocusSlot()
{

}

void vncClientWidgetCls::vncFrameResizeSlot()
{

    this->updateSize();
    emit this->vncFrameResizeSignal();

}

void vncClientWidgetCls::tsbValueChange(int value)
{

    if (this->widgetResizing)
        return;

    if (value == this->BSB->value())
        return;

    qint32 yup = value * -1;
    this->rfbWidget->move(yup,this->rfbWidget->y());
    this->BSB->setSliderPosition(this->TSB->sliderPosition());


}

void vncClientWidgetCls::bsbValueChange(int value)
{
    if (this->widgetResizing)
        return;

    if (value == this->TSB->value())
        return;
    qint32 yup = value * -1;
    this->rfbWidget->move(yup,this->rfbWidget->y());
    this->TSB->setSliderPosition(this->BSB->sliderPosition());

}

void vncClientWidgetCls::lsbValueChange(int value)
{
    if (this->widgetResizing)
        return;

    if (value == this->RSB->value())
        return;
    qint32 yup = value * -1;
    this->rfbWidget->move(this->rfbWidget->x(),yup);
    this->RSB->setSliderPosition(this->LSB->sliderPosition());
}

void vncClientWidgetCls::rsbValueChange(int value)
{
    if (this->widgetResizing)
        return;

    if (value == this->LSB->value())
        return;

    qint32 yup = value * -1;
    this->rfbWidget->move(this->rfbWidget->x(),yup);
    this->LSB->setSliderPosition(this->RSB->sliderPosition());
}

void vncClientWidgetCls::updateSize()
{

    this->setMaximumSize(this->rfbWidget->geometry().width()+20,this->rfbWidget->geometry().height()+20);

    if (this->parentWidget() <=0)
        return;


    if ((this->rfbWidget->geometry().width() + 20) <= this->parentWidget()->geometry().width())
        this->resize(this->rfbWidget->geometry().width()+20,this->geometry().height());

    if ((this->rfbWidget->geometry().height() + 20) <= this->parentWidget()->geometry().height())
        this->resize(this->geometry().width(),this->rfbWidget->geometry().height()+20);

    if ((this->rfbWidget->geometry().width() + 20) > this->parentWidget()->geometry().width())
        this->resize(this->parentWidget()->geometry().width(),this->geometry().height());

    if ((this->rfbWidget->geometry().height()+20) > this->parentWidget()->geometry().height())
        this->resize(this->geometry().width(),this->parentWidget()->geometry().height());

}





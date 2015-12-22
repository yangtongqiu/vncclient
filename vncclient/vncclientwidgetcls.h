#ifndef VNCCLIENTWIDGETCLS_H
#define VNCCLIENTWIDGETCLS_H

#include <QWidget>
#include <QScrollBar>
#include <QFrame>
#include <QPushButton>
#include "rfbclientwidgetcls.h"


class vncClientWidgetCls : public QWidget
{
    Q_OBJECT
public:
    explicit vncClientWidgetCls(QWidget *parent = 0);
    bool connectVNCTCP(QString server, qint16 port=5900);
    bool connectVNCIPC(QString server);
    void disconnectVNC();
    void updateSize();

private:
    rfbclientwidgetcls *rfbWidget;
    QScrollBar *TSB;
    QScrollBar *BSB;
    QScrollBar *LSB;
    QScrollBar *RSB;
    QFrame *vncFrame;
    QPushButton *test;

    bool widgetResizing;

signals:

    void vncFrameResizeSignal();

public slots:

private slots:
    void vncFrameResizeSlot();
    void vncFrameGetFocusSlot();
    void tsbValueChange(int value);
    void bsbValueChange(int value);
    void lsbValueChange(int value);
    void rsbValueChange(int value);

protected:
    void resizeEvent(QResizeEvent *);
    void closeEvent(QCloseEvent *);
    void leaveEvent(QEvent *);
};

#endif // VNCCLIENTWIDGETCLS_H

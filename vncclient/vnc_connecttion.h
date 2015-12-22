#ifndef VNC_CONNECTTION_H
#define VNC_CONNECTTION_H

#include <QDialog>

namespace Ui {
class vnc_connecttion;
}

class vnc_connecttion : public QDialog
{
    Q_OBJECT

public:
    explicit vnc_connecttion(QWidget *parent = 0);
    ~vnc_connecttion();

private slots:
    void on_lineEdit_host_textChanged(const QString &arg1);

    void on_lineEdit_port_textChanged(const QString &arg1);

    void on_OK_button_clicked();

private:
    Ui::vnc_connecttion *ui;

};

#endif // VNC_CONNECTTION_H

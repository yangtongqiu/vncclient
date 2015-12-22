/*
 * Copyright (C) 2013 Azril Azam
 * <azrilazam@gmail.com>
 *
 * Desc
 *
 * This file is a part of the 100% Qt5 VNC RFB-CLIENT implementation without
 * using any 3rd party rfb library
 *
 * main.cpp
 *
 *
 * Qt5 RFB-CLIENT is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * Qt5 RFB-CLIENT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Qt HTML platform plugin. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <QApplication>
#include "vncclientwidgetcls.h"
#include "rfbclientwidgetcls.h"
#include "vncclientwidget2cls.h"
#include "vnc_connecttion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //vnc_connecttion w;
    //w.show();
    vncclientwidget2cls vnc;

    vnc.connectVNCTCP("192.168.1.158", 5901);
    vnc.show();
    return a.exec();
}

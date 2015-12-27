#include "mainwindow.h"
#include <QApplication>
#include <QDateTime>
#include <map>
#include <list>
#include <iostream>
#include "../gpp_qt/wfunction/wfunction.h"
#include"./listen_stdin.h"
using namespace std;

MainWindow * mw;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    mw=&w;

    listen_stdin *ls=new listen_stdin;
    ls->set_mw(&w);
    ls->init();
    ls->start();

    q_button *qb=new q_button();
    qb->init("aaa\n"+QDateTime::currentDateTime().toString("hh:mm:ss").toStdString());

    //emit this->add_button(qb);
    mw->add_button(qb);


    return a.exec();
}
/*

通过两个map存储信息
有新的来之后  在ctrmsg中查找 成功的话 在ctrbutton中设置
                         失败的话 添加新button
*/

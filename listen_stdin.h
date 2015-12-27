#ifndef LISTEN_STDIN_H
#define LISTEN_STDIN_H

#include <QThread>
#include <string>
#include <QDateTime>
#include <map>
#include <list>
#include <iostream>
#include"q_button.h"
#include"mainwindow.h"
#include "../gpp_qt/wfunction/wfunction.h"

class work_t : public QObject
{
    Q_OBJECT
public:
    work_t(){}
    void w1();
signals:
    void add_button(q_button*);
};

class listen_stdin : public QThread
{
    Q_OBJECT
public:
    listen_stdin();

    void set_mw(MainWindow * mw){_mw=mw;}
    void init();
    void run();
    work_t * _work_t;
    MainWindow * _mw;
};


#endif // LISTEN_STDIN_H

#include "mainwindow.h"
#include <QApplication>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    map<string,string> ctr_msg;
    map<string,q_button*> ctr_button;
    MainWindow w;
    w.show();

    return a.exec();
}
/*

通过两个map存储信息
有新的来之后  在ctrmsg中查找 成功的话 在ctrbutton中设置
                         失败的话 添加新button
*/

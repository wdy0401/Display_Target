#include "listen_stdin.h"

using namespace std;

listen_stdin::listen_stdin()
{
}
void listen_stdin::init()
{
    QObject::connect(this,&listen_stdin::add_button,_mw,&MainWindow::add_button);
}
void listen_stdin::run()
{

    map<string,string> ctr_msg;
    map<string,q_button*> ctr_button;

    string tp;
    list<string> ls;
    int i=1;
    while(1)
    {
        QThread::sleep(1);
        tp="IF1501"+wfunction::itos(i)+",123";
        i++;
        cerr << "1\t"  << tp << endl;
        ls=wfunction::splitstring(tp);
        if(ls.size()<2)
        {
            continue;
        }
        string ctr=*(ls.begin());
        string msg=*(++ls.begin());

        cerr << "2\t"  << tp << endl;
        if(ctr_msg.find(ctr)!=ctr_msg.end())
        {
            if(ctr_msg[ctr]==msg)
            {
                continue;
            }
            else
            {
                ctr_msg[ctr]=msg;
                ctr_button[ctr]->change_message(msg+"\n"+QDateTime::currentDateTime().toString("hh:mm:ss").toStdString());
            }
            cerr << "3\t"  << tp << endl;
        }
        else
        {
            qb=new q_button();
            qb->init(msg+"\n"+QDateTime::currentDateTime().toString("hh:mm:ss").toStdString());
            ctr_button[ctr]=qb;
            ctr_msg[ctr]=msg;

            //emit this->add_button(qb);
            emit this->add_button(qb);
            cerr << "4\t"  << tp << endl;
        }
        cerr << "5\t"  << tp << endl;
    }
}

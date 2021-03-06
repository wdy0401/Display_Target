#include<string>

#include "q_button.h"

using namespace std;

q_button::q_button(QObject *parent)
{
}
void q_button::init(const string & message,int status)
{
    _message=message;
    _status=status;

    this->setFixedHeight(75);
    this->setObjectName(QStringLiteral("pushButton"));
    this->setMouseTracking(true);
    this->change_status(_status);
    this->setText(_message.c_str());
}
void q_button::init(const string & message)
{
    init(message,1);
}
void q_button::change_status(int status)
{
    //  yellow  255 255 100
    //  green   38  166 44
    //  blue    41  89  209
    //  red     224 7   2
    //  find in excel

    string color_type;
    switch(status)
    {
        case 0:color_type="background-color: rgb(255,255,100);";break;
        case 1:color_type="background-color: rgb(38,166,44);";break;
        case 2:color_type="background-color: rgb(41,89,209);";break;
        case 3:color_type="background-color: rgb(224,7,2);";break;
        default:color_type="background-color: rgb(150,16,150);";break;
    }
    this->setStyleSheet(color_type.c_str());
}

void q_button::change_message(const string & msg)
{
    this->setText(msg.c_str());
    _message=msg;
}

void q_button::mouseDoubleClickEvent(QMouseEvent *event)
{
    change_status(2);
}

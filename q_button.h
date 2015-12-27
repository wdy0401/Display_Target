#ifndef Q_BUTTON_H
#define Q_BUTTON_H

#include <QPushButton>
#include <QMouseEvent>

#include <string>

class q_button : public QPushButton
{
    Q_OBJECT
public:
    explicit q_button(QObject *parent = 0);
    void init(const std::string & ,int);
    void init(const std::string &);
    void change_message(const std::string & msg);

public slots:
    void change_status(int);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    std::string _message;
    int _status;

};

#endif // Q_BUTTON_H

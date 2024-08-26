#ifndef PASSWORD_H
#define PASSWORD_H
#include <QObject>
#include <QString>
#include <QChar>
#include <QDebug>

class Password : public QObject {
    Q_OBJECT
public:
    Password();
    ~Password();
    bool validStd(QString p);
    bool validSignificantDigit(QString p);
    bool validNoLeadingZero(QString p);
    void setPosition(int i);
private:
    int pos;
};

#endif // PASSWORD_H

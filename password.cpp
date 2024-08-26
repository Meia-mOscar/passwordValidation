#include "password.h"

Password::Password() {
    pos = 0;
}

Password::~Password() {

}

void Password::setPosition(int i) {
    pos = i;
}

bool Password::validStd(QString p) {
    /* length >= 5
     * Contains no spaces
     */
    if(p.length() > 5) {
        if(!p.contains(' ')) {
            return true;
        }
    }
    return false;
}

bool Password::validSignificantDigit(QString p) {
    /* length <= 5
     * 3rd is either number / alphabetical
     */
    QChar c;
    if(p.length() > 5) {
        c = p.at(pos);
        if(c.isNumber() || c.isLetter()) {
            return true;
        }
    }
    return false;
}

bool Password::validNoLeadingZero(QString p) {
    /* 4 <= lentgh >= 6
     * No leading zero
     */
    QChar c;
    int length = p.length();
    if(length > 3 && length < 7) {
        c = p.at(0);
        if(!c.isSpace()) {
            return true;
        }
    }
    return false;
}

#include <iostream>
#include <cstdlib>
using namespace std;
#include "dtime.h"

DigitalTime::DigitalTime(int theHour, int theMinute)
{
    if (theHour < 0 || theHour > 23 || theMinute < 0 || theMinute > 59) {
        cerr << "Illegal argument to DigitalTime constructor." << endl;
        exit(1);
    }
    else {
        hour = theHour;
        minute = theMinute;
    }
    if (hour == 24) {
        hour = 0;
    }
}

DigitalTime::DigitalTime()
{
    hour = 0;
    minute = 0;
}

int DigitalTime::getHour() const
{
    return hour;
}

int DigitalTime::getMinute() const
{
    return minute;
}

void DigitalTime::advance(int minutesAdded)
{
    int grossMinutes = minute + minutesAdded;
    minute = grossMinutes % 60;
    int hourAdjustment = grossMinutes / 60;
    hour = (hour + hourAdjustment) % 24;
}

void DigitalTime::advance(int hoursAdded, int minutesAdded)
{
    hour = (hour + hoursAdded) % 24;
    advance(minutesAdded);
}

bool operator ==(const DigitalTime &time1, const DigitalTime &time2)
{
    return (time1.hour == time2.hour && time1.minute == time2.minute);
}

ostream &operator <<(ostream &outs, const DigitalTime &theObject)
{
    if (theObject.hour < 10) {
        outs << '0';
    }
    outs << theObject.hour << ':';
    if (theObject.minute < 10) {
        outs << '0';
    }
    outs << theObject.minute;
    return outs;
}

istream &operator >>(istream &ins, DigitalTime &theObject)
{
    DigitalTime::readHour(ins, theObject.hour);
    DigitalTime::readMinute(ins, theObject.minute);
    return ins;
}

int DigitalTime::digitToInt(char c)
{
    return static_cast<int> (c) - static_cast<int> ('0');
}

void DigitalTime::readHour(istream &ins, int &theHour)
{
    char c1, c2;
    ins >> c1 >> c2;
    if (!(isdigit(c1) &&  (isdigit(c2) || c2 == ':'))) {
        cerr << "Illegal hour input to readHour\n";
        exit(1);
    }
    if (isdigit(c1) && c2 == ':') {
        theHour = digitToInt(c1);
    }
    else { // (isdigit(c1) && isdigit(c2))
        theHour = digitToInt(c1) * 10 + digitToInt(c2);
        ins >> c2; // discard ':'
        if (c2 != ':') {
            cerr << "Illegal hour input to readHour\n";
            exit(1);
        }
    }
    if (theHour == 24) {
        theHour = 0;
    }
    if (theHour < 0 || theHour > 23) {
        cerr << "Illegal hour input to readHour\n";
        exit(1);
    }
}

void DigitalTime::readMinute(istream &ins, int &theMinute)
{
    char c1, c2;
    ins >> c1 >> c2;
    if (!(isdigit(c1) && isdigit(c2))) {
        cerr << "Illegal minute input to readMinute\n";
        exit(1);
    }
    theMinute = digitToInt(c1) * 10 + digitToInt(c2);
    if (theMinute < 0 || theMinute > 59) {
        cerr << "Illegal minute input to readMinute\n";
        exit(1);
    }
}

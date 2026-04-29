#ifndef PFARRAYDBAK_H
#define PFARRAYDBAK_H

#include "PFArrayD.h"

class PFArrayDBak : public PFArrayD {
public:
    PFArrayDBak();
    PFArrayDBak(int size);
    PFArrayDBak(const PFArrayDBak &object);
    ~PFArrayDBak();
    void backup();
    void restore();
    PFArrayDBak &operator =(const PFArrayDBak &rightSide);
private:
    double *b;
    int usedB;
};

#endif // PFARRAYDBAK_H

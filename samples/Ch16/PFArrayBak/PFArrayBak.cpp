#include "PFArrayBak.h"

namespace PFArrayCAS1102 {

template<class T>
PFArrayBak<T>::PFArrayBak() : PFArray<T>(), usedB(0)
    { b = new T[this->getCapacity()]; }

template<class T>
PFArrayBak<T>::PFArrayBak(int size) : PFArray<T>(size), usedB(0)
    { b = new T[this->getCapacity()]; }

template<class T>
PFArrayBak<T>::PFArrayBak(const PFArrayBak<T> &object)
    : PFArray<T>(object), usedB(object.usedB)
{
    b = new T[this->getCapacity()];
    for (int i = 0; i < usedB; i++) b[i] = object.b[i];
}

template<class T>
PFArrayBak<T>::~PFArrayBak() { delete [] b; }

template<class T>
void PFArrayBak<T>::backup()
{
    usedB = this->getNumberUsed();
    for (int i = 0; i < usedB; i++) b[i] = this->operator [](i);
}

template<class T>
void PFArrayBak<T>::restore()
{
    this->emptyArray();
    for (int i = 0; i < usedB; i++) this->addElement(b[i]);
}

template<class T>
PFArrayBak<T> &PFArrayBak<T>::operator =(const PFArrayBak &rightSide)
{
    int oldCapacity = this->getCapacity();
    PFArray<T>::operator =(rightSide);
    if (oldCapacity != rightSide.getCapacity()) {
        delete [] b;
        b = new T[rightSide.getCapacity()];
    }
    usedB = rightSide.usedB;
    for (int i = 0; i < usedB; i++) b[i] = rightSide.b[i];
    return *this;
}

} // end namespace PFArrayCAS1102

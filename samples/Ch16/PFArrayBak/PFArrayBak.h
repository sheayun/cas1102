#ifndef PFARRAYBAK_H
#define PFARRAYBAK_H

namespace PFArrayCAS1102 {

template<class T>
class PFArrayBak : public PFArray<T> {
public:
    PFArrayBak();
    PFArrayBak(int size);
    PFArrayBak(const PFArrayBak<T> &object);
    virtual ~PFArrayBak();
    void backup();
    void restore();
    PFArrayBak<T> &operator =(const PFArrayBak<T> &rightSide);
private:
    T *b;
    int usedB;
}; // end class PFArrayBak

} // end namespace PFArrayCAS1102

#endif // PFARRAYBAK_H

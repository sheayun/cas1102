#ifndef PFARRAY_H
#define PFARRAY_H

namespace PFArrayCAS1102 {

template<class T>
class PFArray {
public:
    PFArray();
    PFArray(int size);
    PFArray(const PFArray<T> &pfaObject);
    virtual ~PFArray();
    void addElement(const T &element);
    bool full() const;
    void emptyArray();
    int getCapacity() const;
    int getNumberUsed() const;
    T &operator [](int index);
    PFArray<T> &operator =(const PFArray<T> &rightSide);
private:
    T *a;
    int capacity;
    int used;
}; // end class PFArray

} // end namespace PFArrayCAS1102

#endif // PFARRAY_H

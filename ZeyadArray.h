//
// Created by zeyad on 10/31/24.
//

#ifndef ZEYADARRAY_H
#define ZEYADARRAY_H

#include <stdexcept>
using namespace std;

template <class type>
class ZeyadArray {
private:
    int size;
    int capacity;
    type* a;


public:
    ZeyadArray();
    bool isEmpty() const;
    bool isFull() const;
    void append(const type &e);
    void remove();
    void deleteAtIndex(const int &idx);
    void resize(int newCapacity);
    int SIZE() const;
    type & operator[](int idx);
    ~ ZeyadArray();
};
template<class type>
type &ZeyadArray<type>::operator[](int idx) {
    if (idx < 0 || idx >= size) {
        throw out_of_range("Index out of bounds");
    }
    return a [idx];
}

template <class type>
ZeyadArray<type>::ZeyadArray() : size(0), capacity(100) {
    a = new type[capacity];
}

template <class type>
bool ZeyadArray<type>::isEmpty() const {
    return size == 0;
}

template <class type>
bool ZeyadArray<type>::isFull() const {
    return size == capacity;
}


template <class type>
void ZeyadArray<type>::append(const type &e) {
    if (isFull()) {
        resize(static_cast<int>(1.5 * capacity));
    }
    a[size++] = e;
}

template <class type>
void ZeyadArray<type>::remove() {
    if (isEmpty()) throw out_of_range("Array is empty");
    size--;
}

template <class type>
void ZeyadArray<type>::deleteAtIndex(const int &idx) {
    if (idx >= size || idx < 0) throw out_of_range("Invalid index");
    for (int i = idx; i < size - 1; ++i) {
        a[i] = a[i + 1];
    }
    size--;
}

template <class type>
int ZeyadArray<type>::SIZE() const {
    return size;
}

template <class type>
void ZeyadArray<type>::resize(int newCapacity) {
    type* newArray = new type[newCapacity];
    for (int i = 0; i < size; ++i) {
        newArray[i] = a[i];
    }
    delete[] a;
    a = newArray;
    capacity = newCapacity;
}

template <class type>
ZeyadArray<type>::~ZeyadArray() {
    delete[] a;
}

#endif

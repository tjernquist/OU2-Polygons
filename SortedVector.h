
#ifndef SORTECVECTOR_H
#define	SORTECVECTOR_H

#include <iostream>

using namespace std;

template <class T, int size> class SortedVector {
public:
    SortedVector();
    bool add(const T& v);
    T& median();
    void sortArray();
    void removeLarger(const T& v);
    void print(ostream &os);
    void compexch(T& x, T& y);
    void sortArray(T* data, int s);

private:
    T arr[size];
    int arraySize;
};

template <class T, int size> SortedVector<T, size>::SortedVector() {

    arraySize = 0;

    for (int i = 0; i < size; i++) {
        arr[i] = T();
    }
}

template <class T, int size> bool SortedVector<T, size>::add(const T& v) {

    if (arraySize > size - 1) {
        cout << "Array is full!" << endl;
        return false;
    } else {
        arr[arraySize] = v;
        arraySize++;
        sortArray(arr, arraySize);
    }

    return true;
}

template <class T, int size> void SortedVector<T, size>::sortArray(T* data, int s) {
    
    for (int i = 0; i < s - 1; i++) {
        for (int j = i + 1; j < s; j++) {
            compexch(data[i], data[j]);
        }
    }
}

template <class T, int size > T & SortedVector<T, size>::median() {

    if (arraySize % 2 != 0) {
        return arr[arraySize / 2];
    } else {
        return arr[(arraySize / 2) - 1];
    }
}

template <class T, int size> void SortedVector<T, size>::removeLarger(const T & v) {

    for (int i = 0; i < arraySize; i++) {
        if (v < arr[i]) {
            arr[i] = 0;
            arraySize--;
        }
    }
}

template <class T, int size> void SortedVector<T, size>::print(ostream & os) {

    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << endl;
    }
}

template <class T, int size> inline void SortedVector<T, size>::compexch(T& x, T& y) {
    
    if (y < x) {
        T temp = x;
        x = y;
        y = temp;
    }
}

#endif	/* SORTECVECTOR_H */


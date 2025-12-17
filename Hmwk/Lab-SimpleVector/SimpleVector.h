/* 
 * File:   SimpleVector.h
 * Author: Dr. Mark E. Lehr
 * Modified by: Me :)
 * Purpose:  Modified SimpleVector with push & pop functions
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <class T>
class SimpleVector{
private:
    T *aptr;
    int arraySize;
    void memError();
    void subError();

public:
    // Default constructor
    SimpleVector() { aptr = 0; arraySize = 0; }

    // Constructor
    SimpleVector(int);

    // Copy constructor
    SimpleVector(const SimpleVector &);

    // Destructor
    ~SimpleVector();

    // Accessors
    int size() const { return arraySize; }
    T getElementAt(int);

    // Overloaded []
    T &operator[](const int &);

    // Push / Pop
    void pshFrnt(T);
    void pshBack(T);
    T popFrnt();
    T popBack();
};


//*******************************************
// Push Back
//*******************************************
template <class T>
void SimpleVector<T>::pshBack(T newVal){
    T *naptr = new T[arraySize + 1];
    if (!naptr) memError();

    for(int i = 0; i < arraySize; i++)
        naptr[i] = aptr[i];

    naptr[arraySize] = newVal;

    delete [] aptr;
    arraySize++;
    aptr = naptr;
}


//*******************************************
// Push Front
//*******************************************
template <class T>
void SimpleVector<T>::pshFrnt(T newVal){
    T *naptr = new T[arraySize + 1];
    if (!naptr) memError();

    // Shift existing data
    for(int i = 0; i < arraySize; i++)
        naptr[i + 1] = aptr[i];

    naptr[0] = newVal;

    delete [] aptr;
    arraySize++;
    aptr = naptr;
}


//*******************************************
// Pop Back
//*******************************************
template <class T>
T SimpleVector<T>::popBack(){
    if (arraySize == 0)
        subError();

    T oldVal = aptr[arraySize - 1];

    if (arraySize == 1) {
        delete [] aptr;
        aptr = 0;
        arraySize = 0;
        return oldVal;
    }

    T *naptr = new T[arraySize - 1];
    if (!naptr) memError();

    for(int i = 0; i < arraySize - 1; i++)
        naptr[i] = aptr[i];

    delete [] aptr;
    aptr = naptr;
    arraySize--;

    return oldVal;
}


//*******************************************
// Pop Front
//*******************************************
template <class T>
T SimpleVector<T>::popFrnt(){
    if (arraySize == 0)
        subError();

    T oldVal = aptr[0];

    if (arraySize == 1) {
        delete [] aptr;
        aptr = 0;
        arraySize = 0;
        return oldVal;
    }

    T *naptr = new T[arraySize - 1];
    if (!naptr) memError();

    for(int i = 0; i < arraySize - 1; i++)
        naptr[i] = aptr[i + 1];

    delete [] aptr;
    aptr = naptr;
    arraySize--;

    return oldVal;
}


//*******************************************
// Constructor
//*******************************************
template <class T>
SimpleVector<T>::SimpleVector(int s){
    arraySize = s;

    try {
        aptr = new T[s];
    } catch (bad_alloc) {
        memError();
    }

    for (int i = 0; i < arraySize; i++)
        aptr[i] = 0;
}


//*******************************************
// Copy Constructor
//*******************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
    arraySize = obj.arraySize;
    aptr = new T[arraySize];
    if (!aptr) memError();

    for(int i = 0; i < arraySize; i++)
        aptr[i] = obj.aptr[i];
}


//*******************************************
// Destructor
//*******************************************
template <class T>
SimpleVector<T>::~SimpleVector(){
    if (arraySize > 0)
        delete [] aptr;
}


//*******************************************
// Memory error handler
//*******************************************
template <class T>
void SimpleVector<T>::memError(){
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}


//*******************************************
// Subscript error handler
//*******************************************
template <class T>
void SimpleVector<T>::subError(){
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}


//*******************************************
// getElementAt
//*******************************************
template <class T>
T SimpleVector<T>::getElementAt(int sub){
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}


//*******************************************
// Overloaded []
//*******************************************
template <class T>
T &SimpleVector<T>::operator[](const int &sub){
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif

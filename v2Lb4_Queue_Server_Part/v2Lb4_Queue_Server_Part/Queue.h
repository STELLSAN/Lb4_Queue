#pragma once
#include "iostream"

template <class T>
class Queue {
    //friend class Iterator;
private:
    T* _data;
    //int memSize, dataCount ;
    size_t _firstIndex;
    size_t _lastIndex;
    size_t _count = 0;
    size_t _size = 0;
    T* _begin;
    T* _end;
public:
    T* Begin() { return _begin; }

    T* End() { return _end; }

    Queue(size_t size = 10) :_size(size) {
        _data = new T[size];
        _firstIndex = 0;
        _lastIndex = 0;
    };

    bool IsEmpty() const { return _count == 0; };

    bool IsFull() const { return _count == _size; };

    void Push(const T& t) {
        if (IsFull()) {
            throw std::range_error("Push_error");
        }
        _data[_lastIndex] = t;
        _lastIndex = (_lastIndex + 1) % _size;
        _count++;

    };

    T Pop() {
        if (IsEmpty()) {
            throw std::range_error("error_Pop");
        }
        T firstElem = _data[_firstIndex];
        _firstIndex = (_firstIndex + 1) % _size;
        _count++;
        return firstElem;
    };

    T Top() {
        if (IsEmpty()) throw std::range_error("error");
        return _data[_firstIndex];
    };

    void Print() {
        if (!IsEmpty()) {
            int i = _firstIndex;
            do {
                std::cout << _data[i];
                i = (i + 1) % _size;
            } while (i != _lastIndex);
        }
    }
};

/*
*
* The iterator implies moving through the queue, because the queue class itself is responsible only for the work of including elements in the queue?
*
*
* The following overloads should be enabled:
    ++ - to move to one element (and reset to the beginning)
    * - access to the element (creating a copy?)
    ==/!= - Comparison of pointers, to understand the end of the list
*/
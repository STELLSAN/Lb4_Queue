#pragma once
#include "iostream"

template <class T>
class Queue
{
private:
	T* _data;
	size_t _size;
	size_t _count;
	size_t _firstIndex;
	size_t _lastIndex;

	size_t _currentIndex;


public:

	Queue(size_t size = 10) : _size(size) {
		_data = new T[size];
		_firstIndex = 0;
		_lastIndex = 0;
	}
	bool IsEmpty() {
		return _count == 0;
	}
	bool IsFull() {
		return _count == _size;
	}

	void Add(T& t) {
		if (IsFull())
			throw std::range_error("Queue is full");

		size_t nextIndex = (_lastIndex + 1) % _size;
		if (nextIndex != _firstIndex) {
			_data[_lastIndex] = t;
			_lastIndex = (_lastIndex + 1) % _size;
			_count++;
		}
	}

	T Get() {
		if (IsEmpty())
			throw std::range_error("Queue is empty");

		T firstElem = _data[_firstIndex];
		_firstIndex = (_firstIndex + 1) % _size;
		_count--;

		return firstElem;
	}

	void Reset() {
		_currentIndex = _firstIndex;
	}

	bool IsEnd() {
		return _currentIndex == _lastIndex;
	}

	void Next() {
		_currentIndex = (_currentIndex + 1) % _size;
	}

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
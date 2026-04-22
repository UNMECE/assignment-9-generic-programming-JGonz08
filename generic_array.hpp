#ifndef GENERIC_ARRAY_HPP
#define GENERIC_ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* data;
    int length;

public:
    GenericArray() : data(nullptr), length(0) {}

    ~GenericArray() {
        delete[] data;
    }

    void addElement(T value) {
        T* newData = new T[length + 1];

        for (int i = 0; i < length; i++)
            newData[i] = data[i];

        newData[length] = value;

        delete[] data;
        data = newData;
        length++;
    }

    T at(int index) const {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    int size() const {
        return length;
    }

    T sum() const {
        if (length == 0) return 0;
        T total = 0;
        for (int i = 0; i < length; i++)
            total += data[i];
        return total;
    }

    T max() const {
        if (length == 0) throw std::runtime_error("Array empty");
        T m = data[0];
        for (int i = 1; i < length; i++)
            if (data[i] > m) m = data[i];
        return m;
    }

    T min() const {
        if (length == 0) throw std::runtime_error("Array empty");
        T m = data[0];
        for (int i = 1; i < length; i++)
            if (data[i] < m) m = data[i];
        return m;
    }

    T* slice(int begin, int end) const {
        if (begin < 0 || end >= length || begin > end)
            throw std::out_of_range("Invalid slice bounds");

        int newSize = end - begin + 1;
        T* newArr = new T[newSize];

        for (int i = 0; i < newSize; i++)
            newArr[i] = data[begin + i];

        return newArr; // caller must delete[]
    }
};

#endif


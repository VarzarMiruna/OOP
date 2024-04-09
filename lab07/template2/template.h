#pragma once
#include <iostream>
#include <algorithm> 

template <typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize() {
        capacity = capacity * 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Vector() : data(nullptr), capacity(1), size(0) {
        data = new T[capacity];
    }

    ~Vector() {
        if (data)
        {
            free(data);
            data = NULL;
        }
    }

    Vector(const Vector& other) : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
        std::copy(other.data, other.data + other.size, data);
    }

    Vector(Vector&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    void insert(size_t index, const T& element) {
        if (size == capacity) {
            resize();
        }
        if (index > size) index = size;
        for (size_t i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        size++;
    }

    void remove(size_t index) {
        if (index >= size) return;
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void sort(int (*compare_ints)(T, T)) {
        int temp;

        if (compare_ints == nullptr)
        {
            for (int i = 0; i < size - 1; i++)
                for (int j = i + 1; j < size; j++)
                {
                    if ((data[i] > data[j]))
                    {
                        temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
        }
        else
        {

            for (int i = 0; i < size - 1; i++)
                for (int j = i + 1; j < size; j++)
                {
                    if (compare_ints(data[i], data[j]))
                    {
                        temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
        }
    }

    /*
    void sort() {
        std::sort(data, data + size);
    }*/

    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    T& operator[](size_t index) {
        return data[index];
    }
};



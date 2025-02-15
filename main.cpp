#include <iostream>
#include <stdexcept>

template<typename T>

class MyVector {
private:
    T* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for(size_t i = 0; i < sz; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    MyVector() : data(nullptr), sz(0), cap(0) { }
    ~MyVector() { delete[] data; }

    MyVector(const MyVector& other) : sz(other.sz), cap(other.cap) {
        data = new T[cap];
        for(size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    MyVector& operator=(const MyVector& other) {
        if(this!=other) {
            delete[] data;
            sz = other.sz;
            cap = other.cap;
            data = new T[cap];
            for (size_t i = 0; i < sz; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if(sz >= cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            reallocate(new_cap);
        }
        data[sz++] = value;
    }

    void pop_back() {
        if(sz==0) {
            throw std::out_of_range("Vector is empty");
        }
        --sz;
    }

    size_t size() const {
        return sz;
    }

    T& operator[](size_t index) {
        if(index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator[](size_t index) const {
        if(index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

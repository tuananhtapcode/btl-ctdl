#ifndef iterator__cpp
#define iterator__cpp

template <class T>
class reverse_iterator {
    T *pointer;

public:
    reverse_iterator(T *pointer = nullptr) : pointer(pointer) {}

    void operator=(const reverse_iterator<T> &it) {
        pointer = it.pointer;
    }

    T &operator*() {
        return *pointer;
    }

    const T &operator*() const {
        return *pointer;
    }

    reverse_iterator<T> operator++() { // ++pointer
        --pointer;
        return *this;
    }

    reverse_iterator<T> operator++(int) { // pointer++
        reverse_iterator<T> tmp = *this;
        --pointer;
        return tmp;
    }

    reverse_iterator<T> operator--() { // --pointer
        ++pointer;
        return *this;
    }

    reverse_iterator<T> operator--(int) { // pointer--
        reverse_iterator<T> tmp = *this;
        ++pointer;
        return tmp;
    }

    bool operator>=(const reverse_iterator<T> &it) const {
        return pointer <= it.pointer;
    }

    bool operator>(const reverse_iterator<T> &it) const {
        return pointer < it.pointer;
    }

    bool operator<=(const reverse_iterator<T> &it) const {
        return pointer >= it.pointer;
    }

    bool operator<(const reverse_iterator<T> &it) const {
        return pointer > it.pointer;
    }

    bool operator!=(const reverse_iterator<T> &it) const {
        return pointer != it.pointer;
    }

    reverse_iterator<T> operator+(long long val) const {
        return pointer - val;
    }

    reverse_iterator<T> operator-(long long val) const {
        return pointer + val;
    }

    long long operator-(const reverse_iterator<T> &it) const {
        return it.pointer - pointer;
    }
};

template <class T>
class vector_iterator {
    T *pointer;

public:
    vector_iterator(T *pointer = nullptr) : pointer(pointer) {}

    void operator=(const vector_iterator<T> &it) {
        pointer = it.pointer;
    }

    T &operator*() {
        return *pointer;
    }

    const T &operator*() const {
        return *pointer;
    }

    vector_iterator<T> operator++() { // ++pointer
        ++pointer;
        return *this;
    }

    vector_iterator<T> operator++(int) { // pointer++
        vector_iterator<T> tmp = *this;
        ++pointer;
        return tmp;
    }

    vector_iterator<T> operator--() { // --pointer
        --pointer;
        return *this;
    }

    vector_iterator<T> operator--(int) { // pointer--
        vector_iterator<T> tmp = *this;
        --pointer;
        return tmp;
    }

    bool operator>=(const vector_iterator<T> &it) const {
        return pointer >= it.pointer;
    }

    bool operator>(const vector_iterator<T> &it) const {
        return pointer > it.pointer;
    }

    bool operator<=(const vector_iterator<T> &it) const {
        return pointer <= it.pointer;
    }

    bool operator<(const vector_iterator<T> &it) const {
        return pointer < it.pointer;
    }

    bool operator!=(const vector_iterator<T> &it) const {
        return pointer != it.pointer;
    }

    vector_iterator<T> operator+(long long val) const {
        return pointer + val;
    }

    vector_iterator<T> operator-(long long val) const {
        return pointer - val;
    }

    long long operator-(const vector_iterator<T> &it) const {
        return pointer - it.pointer;
    }

    long long operator+(const vector_iterator<T> &it) const {
        return pointer + it.pointer;
    }
};

#endif

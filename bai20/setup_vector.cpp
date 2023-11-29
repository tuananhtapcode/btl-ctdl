#include <iostream>
#include "iterator.cpp"

using namespace std;

template <class T>
class Vector
{
private:
    size_t capacity, num;
    T *vt;

public:
    Vector()
    {
        capacity = 1;
        num = 0;
        vt = new T[capacity];
    }
    Vector(int k, T x = 0)
    {
        capacity = num = k;
        for (size_t i = 0; i < k; i++)
        {
            vt[i] = x;
        }
    }
    ~Vector()
    {
        if (vt)
            delete[] vt;
    }
    size_t size() const { return num; }
    size_t get_capacity() const { return capacity; }
    T &front() { return vt[0]; }
    T &back() { return vt[num - 1]; }
    T &operator[](int k) { return vt[k]; }
    bool empty()
    {
        if (num == 0)
        {
            return true;
        }
        return false;
    }
    void pop_back()
    {
        if (num > 0)
            num--;
    }
    void extend(size_t new_capacity)
    {
        if (new_capacity <= capacity)
        {
            return;
        }
        capacity = new_capacity;
        T *temp = new T[capacity];
        for (int i = 0; i < num; i++)
            temp[i] = vt[i];
        if (vt)
            delete[] vt;
        vt = temp;
    }
    void resize(size_t newsize, T x)
    {
        if (newsize <= num)
        {
            num = newsize;
            return;
        }
        if (capacity < newsize)
            extend(newsize);
        for (size_t i = num; i < newsize; i++)
        {
            vt[i] = x;
        }
        num = newsize;
    }
    void push_back(T x)
    {
        if (num == capacity)
            extend(capacity * 2);
        if (vt == NULL)
            vt = new T(1);
        vt[num++] = x;
    }
    void insert(size_t k, T val)
    {
        if (num == capacity)
        {
            extend(capacity * 2);
        }
        for (size_t i = num + 1; i > k; i--)
        {
            vt[i] = vt[i - 1];
        }
        vt[k] = val;
        num++;
    }

typedef vector_iterator<T> iterator;
typedef const vector_iterator<T> const_iterator;
typedef vector_iterator<T> reverse_iterator;
typedef const vector_iterator<T> const_reverse_iterator;

// ...
iterator begin() { return iterator(vt); }
const_iterator begin() const { return const_iterator(vt); }
iterator end() { return iterator(vt + num); }
const_iterator end() const { return const_iterator(vt + num); }
reverse_iterator rbegin() { return reverse_iterator(vt + num - 1); }
const_reverse_iterator rbegin() const { return const_reverse_iterator(vt + num - 1); }
reverse_iterator rend() { return reverse_iterator(vt - 1); }
const_reverse_iterator rend() const { return const_reverse_iterator(vt - 1); }

// ...

    void erase(size_t k)
    {
        if (k < 0 || k >= num)
            return;
        for (size_t i = k - 1; i < num - 1; i++)
        {
            vt[i] = vt[i + 1];
        }
        num--;
    }
    void erase(iterator first, iterator last)
    {
        if (first >= end() || last >= end())
            return;
        T *pos = first;
        while (pos != last)
        {
            *pos = *(pos + (last - first));
            pos++;
        }
        num -= last - first;
    }

    void clear()
    {
        if (vt)
        {
            delete[] vt;
        }
        num = 0;
        vt = nullptr;
    }
    iterator find(iterator first, iterator last, const T &value)
    {
        while (first != last)
        {
            if (*first == value)
            {
                return first;
            }
            ++first;
        }
        return last;
    }
};

int main()
{
    Vector<int> a;
    for (int i = 1; i <= 5; i++)
        a.push_back(i);
    // zVector<int>::reverse_iterator it = a.rbegin();
    cout << "Before clear iterator: ";
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;
    a.clear();
    cout << "After clear iterator: ";
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "Check empty: " << a.empty() << endl;
    cout << "Adding int from 1 to 5..." << endl;
    for (int i = 1; i <= 5; i++)
        a.push_back(i);
    cout << "Last iterator: ";
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
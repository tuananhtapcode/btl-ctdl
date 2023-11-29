#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> arr;

    void swap(int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return i * 2 + 1;
    }

    int right(int i)
    {
        return i * 2 + 2;
    }

    void maxHeapify(int i)
    {
        int leftChild = left(i);
        int rightChild = right(i);
        int largest = i;

        if (leftChild < arr.size() && arr[leftChild] > arr[i])
            largest = leftChild;
        if (rightChild < arr.size() && arr[rightChild] > arr[largest])
            largest = rightChild;

        if (largest != i)
        {
            swap(i, largest);
            maxHeapify(largest);
        }
    }

public:
    void push(int k)
    {
        arr.push_back(k);
        int i = arr.size() - 1;

        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }
    void pop()
    {
        if (arr.size() <= 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        // int root = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        maxHeapify(0);
    }
    int size() { return arr.size(); }
    size_t size() const { return arr.size(); }
    int top() { return arr[0]; }
    int top() const { return arr[0]; }
    bool empty() { return arr.size() == 0; }
    bool empty() const { return arr.size() == 0; }
};

int main()
{
    int n;
    cout << "nhap so luong phan tu trong cay:";
    cin >> n;
    MaxHeap heap;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        heap.push(x);
    }
    cout << "----";
    cout << "Day giam dan la: ";
    while (!heap.empty())
    {
        int temp = heap.top();
        heap.pop();
        cout << temp << " ";
    }
    cout << "----";
    return 0;

    return 0;
}
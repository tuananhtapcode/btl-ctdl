#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thanh kim loai: ";
    cin >> n;

    priority_queue<int, vector<int>> pq; // Min heap
    cout << "Nhap do dai cac thanh kim loai: ";
    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;
        pq.push(length);
    }

    int totalCost = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int cost = a + b;
        totalCost += cost;

        pq.push(cost); // Thêm thanh kim loại đã nối trở lại heap
    }

    cout << "Tong chi phi it nhat: " << totalCost << endl;

    return 0;
}

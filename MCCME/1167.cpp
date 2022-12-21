#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Heap {
    vector<int> a;

    int up(int index) {
        while (index && a[index] > a[(index - 1) / 2]) {
            swap(a[index], a[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        return index;
    }

    int down(int index) {
        while (index * 2 + 1 < a.size()) {
            int maxChild = index * 2 + 1;
            if (maxChild + 1 < a.size() && a[maxChild] < a[maxChild + 1])
                maxChild++;
            if (a[index] >= a[maxChild])
                break;
            swap(a[index], a[maxChild]);
            index = maxChild;
        }
        return index;
    }

    int size() {
        return a.size();
    }

    int push(int value) {
        a.push_back(value);
        return up(a.size() - 1);
    }

    pair<int, int> pop() {
        int value = a[0];
        a[0] = a.back();
        a.pop_back();
        return { a.empty() ? -1 : down(0), value };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int capacity, queryCount;
    cin >> capacity >> queryCount;

    Heap heap;
    for (int i = 0; i < queryCount; i++) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            if (heap.size() == 0) {
                cout << "-1\n";
            } else {
                auto [index, value] = heap.pop();
                cout << index + 1 << " " << value << "\n";
            }
        } else {
            int value;
            cin >> value;

            if (heap.size() == capacity)
                cout << "-1\n";
            else
                cout << heap.push(value) + 1 << "\n";
        }
    }

    for (int value : heap.a)
        cout << value << " ";
}
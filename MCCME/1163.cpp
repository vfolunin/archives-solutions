#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void down(vector<int> &a, int size, int index) {
    while (index * 2 + 1 < size) {
        int maxChild = index * 2 + 1;
        if (maxChild + 1 < size && a[maxChild] < a[maxChild + 1])
            maxChild++;
        if (a[index] >= a[maxChild])
            break;
        swap(a[index], a[maxChild]);
        index = maxChild;
    }
}

void print(vector<int> &a, int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = size / 2; i >= 0; i--)
        down(a, a.size(), i);
    print(a, a.size());

    for (int size = a.size(); size > 1; ) {
        swap(a[0], a[--size]);
        down(a, size, 0);
        print(a, size);
    }

    print(a, a.size());
}
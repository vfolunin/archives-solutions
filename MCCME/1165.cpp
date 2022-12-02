#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index, delta;
        cin >> index >> delta;

        index--;
        a[index] -= delta;

        while (index * 2 + 1 < a.size()) {
            int maxChild = index * 2 + 1;
            if (maxChild + 1 < a.size() && a[maxChild] < a[maxChild + 1])
                maxChild++;
            if (a[index] >= a[maxChild])
                break;
            swap(a[index], a[maxChild]);
            index = maxChild;
        }

        cout << index + 1 << "\n";
    }

    for (int value : a)
        cout << value << " ";
}
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
    cin >> size >> size;

    vector<vector<int>> a(size);
    for (vector<int> &a : a) {
        int count;
        cin >> count;

        a.resize(count);
        for (int &value : a)
            cin >> value;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int from, to, count;
        cin >> from >> to >> count;
        from--;
        to--;

        a[to].insert(a[to].end(), a[from].end() - count, a[from].end());
        a[from].erase(a[from].end() - count, a[from].end());
    }

    for (vector<int> &a : a) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
    }
}
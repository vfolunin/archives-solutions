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

    vector<vector<int>> a(2);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        a[value % 2].push_back(value);
    }

    for (int i : { 1, 0 }) {
        for (int value : a[i])
            cout << value << " ";
        cout << "\n";
    }
    cout << (a[0].size() >= a[1].size() ? "YES" : "NO");
}
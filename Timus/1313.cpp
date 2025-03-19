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

    vector<vector<int>> a(size * 2 + 1);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            a[y + x].push_back(value);
        }
    }

    for (vector<int> &a : a) {
        reverse(a.begin(), a.end());
        for (int value : a)
            cout << value << " ";
    }
}
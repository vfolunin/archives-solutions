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

    for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
        if (a[l] != a[r]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}
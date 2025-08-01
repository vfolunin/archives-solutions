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

    for (int delta = 1; delta * 2 <= size; delta++) {
        bool ok = 1;
        for (int i = delta - 1; i + delta < size && ok; i += delta)
            ok &= a[i] < a[i + delta];

        if (ok) {
            cout << delta;
            return 0;
        }
    }

    cout << "ABORT!";
}
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

    int size, targetSize, mod;
    cin >> size >> targetSize >> mod;

    vector<vector<int>> a(mod);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        a[value % mod].push_back(value);
    }

    for (vector<int> &a : a) {
        if (a.size() >= targetSize) {
            cout << "Yes\n";
            for (int i = 0; i < targetSize; i++)
                cout << a[i] << " ";
            return 0;
        }
    }

    cout << "No";
}
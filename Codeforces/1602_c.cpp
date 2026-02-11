#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> bitCount(30);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        for (int bit = 0; bit < bitCount.size(); bit++) {
            if (value & (1 << bit))
                bitCount[bit]++;
        }
    }

    for (int d = 1; d <= size; d++) {
        bool ok = 1;
        for (int count : bitCount)
            ok &= count % d == 0;

        if (ok)
            cout << d << " ";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
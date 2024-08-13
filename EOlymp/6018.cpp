#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int queryCount, size;
    cin >> queryCount >> size;

    int xorSum = 0;
    multiset<int> values;

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "insert") {
            int value;
            cin >> value;

            xorSum ^= value;
            values.insert(value);

            if (values.size() > size) {
                xorSum ^= *values.begin();
                values.erase(values.begin());
            }
        } else {
            cout << xorSum << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
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

    set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    cout << *values.lower_bound(values.size()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
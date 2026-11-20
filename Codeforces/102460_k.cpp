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

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    long long res = 0;
    while (values.size() > 1) {
        int valueA = *values.begin();
        values.erase(values.begin());
        int valueB = *values.begin();
        values.erase(values.begin());
        res += valueA + valueB;
        values.insert(valueA + valueB);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> hasQuery(size + 1);
    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        hasQuery[value] ^= 1;
    }

    vector<int> a(size);
    for (int value = 1; value < hasQuery.size(); value++)
        if (hasQuery[value])
            for (int j = value - 1; j < a.size(); j += value)
                a[j] ^= 1;

    cout << count(a.begin(), a.end(), 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
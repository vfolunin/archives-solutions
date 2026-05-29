#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    unordered_set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    int mex = 0;
    while (values.count(mex))
        mex++;

    cout << mex << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
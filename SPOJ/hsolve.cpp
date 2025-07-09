#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    unordered_set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    int value;
    cin >> value;

    cout << "Case " << test << ": " << (values.count(value) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}
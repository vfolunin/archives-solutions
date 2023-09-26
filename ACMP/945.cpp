#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, queryCount;
    cin >> size >> queryCount;

    unordered_set<long long> values;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        values.insert(value);
    }

    for (int i = 0; i < queryCount; i++) {
        long long value;
        cin >> value;

        cout << (values.count(value) ? "YES " : "NO ");
    }
}
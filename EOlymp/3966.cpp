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

    int size;
    cin >> size;

    unordered_set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        cout << (values.count(value) ? "YES\n" : "NO\n");
    }
}
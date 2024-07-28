#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_set<int> values;
    int value;

    while (cin >> value) {
        cout << (values.count(value) ? "YES\n" : "NO\n");
        values.insert(value);
    }
}
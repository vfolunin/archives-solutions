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

    while (cin.peek() != '\n') {
        cin >> value;
        values.insert(value);
    }

    int res = 0;

    while (cin >> value)
        res += values.count(value);

    cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    unordered_set<int> values;
    for (int i = 0; i < 6 * size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    cout << (values.size() == 49 ? "Yes\n" : "No\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
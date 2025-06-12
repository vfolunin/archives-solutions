#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value, count;
    cin >> value >> count;

    unordered_map<int, int> seen;
    bool found = 0;

    for (int i = 0; i < count; i++) {
        if (seen.count(value) && !found) {
            int cycleSize = i - seen[value];
            count = i + (count - i) % cycleSize;
            found = 1;
        }
        seen[value] = i;

        if (i < count)
            value = value / 10 + value % 10 * 100;
    }

    cout << value;
}
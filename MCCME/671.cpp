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

    int value, index;
    cin >> value >> index;

    unordered_map<int, int> seen = { { value, 1 } };
    bool found = 0;

    for (int i = 2; i <= index; i++) {
        value = value * value % 10000;
        if (seen.count(value) && !found) {
            int cycleSize = i - seen[value];
            int remaining = index - i;
            index = i + remaining % cycleSize;
            found = 1;
        }
        seen[value] = i;
    }

    cout << value;
}
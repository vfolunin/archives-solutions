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

    unordered_map<int, int> seen;
    for (int i = 0; i < index; i++) {
        if (seen.count(value)) {
            int cycleLen = i - seen[value];
            int remainingLen = index - i;
            
            for (i += remainingLen / cycleLen * cycleLen; i < index; i++) {
                value *= value;
                while (value >= 100)
                    value /= 10;
            }

            break;
        }

        seen[value] = i;

        value *= value;
        while (value >= 100)
            value /= 10;
    }

    cout << value;
}
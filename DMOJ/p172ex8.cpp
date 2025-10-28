#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<int, int> count;
    int maxCount = 0;

    while (1) {
        int value;
        cin >> value;

        if (value == -1)
            break;

        maxCount = max(maxCount, ++count[value]);
    }

    for (auto &[value, count] : count)
        if (count == maxCount)
            cout << value << "\n";
}
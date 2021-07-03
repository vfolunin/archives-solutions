#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int childrenCount, neighborCount;
    cin >> childrenCount >> neighborCount;

    if (!childrenCount)
        return 0;

    vector<int> sweets(neighborCount);
    for (int &s : sweets) {
        cin >> s;
        s %= childrenCount;
    }

    int sum = 0;
    map<int, int> seen = { {sum, -1} };

    for (int i = 0; i < neighborCount; i++) {
        sum = (sum + sweets[i]) % childrenCount;
        if (seen.count(sum)) {
            for (int j = seen[sum] + 1; j <= i; j++)
                cout << j + 1 << (j < i ? " " : "\n");
            break;
        }
        seen[sum] = i;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
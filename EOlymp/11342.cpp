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

    int size;
    cin >> size;

    int remainder = 0;
    unordered_map<int, int> seen = { { remainder, -1 } };
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        remainder = (remainder + value) % size;

        if (seen.count(remainder)) {
            cout << seen[remainder] + 2 << " " << i + 1;
            return 0;
        }

        seen[remainder] = i;
    }

    cout << "-1 -1";
}
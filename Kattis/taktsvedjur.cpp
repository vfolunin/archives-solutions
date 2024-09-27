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

    int size;
    cin >> size;

    vector<int> multipliers = { 1, 2, 4, 8 };
    vector<int> thresholds = { 2, 4, 8, (int)1e9 };
    int mode = 0, row = 0, res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value) {
            row++;
            if (row == thresholds[mode]) {
                mode++;
                row = 0;
            }

            res += multipliers[mode] * value;
        } else {
            mode = max(mode - 1, 0);
            row = 0;
        }
    }

    cout << res;
}
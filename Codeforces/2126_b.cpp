#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, width;
    cin >> size >> width;

    int row = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value) {
            if (row >= width) {
                res++;
                row -= width;
            }
            res += row / (width + 1);
            row = 0;
        } else {
            row++;
        }
    }
    if (row >= width) {
        res++;
        row -= width;
    }
    res += row / (width + 1);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    int area = 0;
    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;

        bool in = 0;
        for (char c : row) {
            if (c != '.') {
                in ^= 1;
                area++;
            } else if (in) {
                area += 2;
            }
        }
    }
    
    cout << area / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
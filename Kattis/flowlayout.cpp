#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int limit;
    cin >> limit;

    if (!limit)
        return 0;

    int totalH = 0, totalW = 0;
    int rowH = 0, rowW = 0;

    while (1) {
        int h, w;
        cin >> w >> h;

        if (h == -1 && w == -1) {
            totalH += rowH;
            totalW = max(totalW, rowW);
            break;
        }

        if (rowW + w <= limit) {
            rowH = max(rowH, h);
            rowW += w;
        } else {
            totalH += rowH;
            totalW = max(totalW, rowW);
            rowH = h;
            rowW = w;
        }
    }

    cout << totalW << " x " << totalH << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
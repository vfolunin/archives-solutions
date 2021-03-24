#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w, r1, r2;
    cin >> h >> w >> r1 >> r2;
    
    if (!h && !w)
        return 0;

    if (min(h, w) < 2 * max(r1, r2)) {
        cout << "N\n";
        return 1;
    }
    
    h -= r1 + r2;
    w -= r1 + r2;

    cout << (h * h + w * w >= (r1 + r2) * (r1 + r2) ? "S\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
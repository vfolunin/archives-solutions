#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    string line;
    cin >> line;

    int lastR = -1e9, lastD = -1e9, minDist = n;
    for (int i = 0; i < n; i++) {
        if (line[i] == 'Z') {
            minDist = 0;
        } else if (line[i] == 'R') {
            minDist = min(minDist, i - lastD);
            lastR = i;
        } else if (line[i] == 'D') {
            minDist = min(minDist, i - lastR);
            lastD = i;
        }
    }

    cout << minDist << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int packetCount;
    cin >> packetCount;

    if (packetCount == -1)
        return 0;

    vector<int> packet(packetCount);
    int mean = 0;
    for (int &x : packet) {
        cin >> x;
        mean += x;
    }

    if (mean % packetCount) {
        cout << "-1\n";
        return 1;
    }

    mean /= packetCount;

    int res = 0;
    for (int x : packet)
        res += max(0, x - mean);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
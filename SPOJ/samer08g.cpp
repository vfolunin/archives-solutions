#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int carCount;
    cin >> carCount;

    if (!carCount)
        return 0;

    vector<pair<int, int>> pole(carCount);
    for (auto &[n, shift] : pole)
        cin >> n >> shift;

    vector<int> start(carCount, -1);
    for (int i = 0; i < carCount; i++) {
        auto &[n, shift] = pole[i];
        if (0 <= i + shift && i + shift < carCount && start[i + shift] == -1) {
            start[i + shift] = n;
        } else {
            cout << "-1\n";
            return 1;
        }
    }

    for (int i = 0; i < carCount; i++)
        cout << start[i] << (i + 1 < carCount ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
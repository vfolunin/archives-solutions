#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int houseCount;
    cin >> houseCount;

    vector<pair<char, int>> houses(houseCount);
    vector<int> side(4);
    int sideIndex = 3;

    for (auto &[type, size] : houses) {
        cin >> type >> size;
        if (type == 'C') {
            side[sideIndex] += size;
            sideIndex = (sideIndex + 1) % 4;
        }
        side[sideIndex] += size;
    }

    int width = max(side[0], side[2]);
    int height = max(side[1], side[3]);

    static const double SQRT34 = sqrt(3) / 4;

    double area = width * height;
    for (auto &[type, size] : houses) {
        if (type == 'T')
            area -= size * size * SQRT34;
        else
            area -= size * size;
    }

    cout.precision(4);
    cout << fixed << area << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
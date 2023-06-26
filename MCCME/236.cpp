#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getCoords(int value) {
    int x = sqrt(value - 1);
    int y = value - (x * x + x + 1);
    return { y, x };
}

bool validCoords(int y, int x) {
    return 0 <= x && -x <= y && y <= x;
}

int getValue(int y, int x) {
    return x * x + x + 1 + y;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value;
    cin >> value;

    auto [y, x] = getCoords(value);

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    vector<int> res;

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (validCoords(ty, tx))
            res.push_back(getValue(ty, tx));
    }

    sort(res.begin(), res.end());

    for (int value : res)
        cout << value << " ";
}
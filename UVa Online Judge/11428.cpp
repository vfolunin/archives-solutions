#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> prepareCubes() {
    map<int, int> cubes = { {1, 1} };
    for (int i = 2; 1; i++) {
        int cube = i * i * i;
        if (cube - cubes.rbegin()->first > 1e4)
            break;
        cubes[cube] = i;
    }
    return cubes;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static map<int, int> cubes = prepareCubes();
    for (auto &[yCube, y] : cubes) {
        auto it = cubes.find(yCube + n);
        if (it != cubes.end()) {
            int x = it->second;
            cout << x << " " << y << "\n";
            return 1;
        }
    }

    cout << "No solution\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
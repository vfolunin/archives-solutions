#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double rec(int hp1, int hp2, int limit, int dmg, int depth) {
    if (hp1 <= 0)
        return 0;
    if (hp2 <= 0)
        return 1;

    static vector<vector<vector<vector<vector<double>>>>> memo(21,
        vector<vector<vector<vector<double>>>>(21,
            vector<vector<vector<double>>>(6,
                vector<vector<double>>(11, vector<double>(301, -1))
                )
            )
    );

    double &res = memo[hp1][hp2][limit][dmg][depth];
    if (res != -1)
        return res;

    if (depth == 300)
        return res = 0.5;

    double p = limit / 6.0;
    return res = p * rec(hp1 + dmg, hp2 - dmg, limit, dmg, depth + 1) +
        (1 - p) * rec(hp1 - dmg, hp2 + dmg, limit, dmg, depth + 1);
}

bool solve() {
    int hp1, hp2, limit, dmg;
    cin >> hp1 >> hp2 >> limit >> dmg;

    if (!hp1)
        return 0;

    cout.precision(1);
    cout << fixed << 100 * rec(hp1, hp2, limit, dmg, 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
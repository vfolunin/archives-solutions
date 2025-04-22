#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int diceCount, sideCount;
    if (!(cin >> diceCount >> sideCount))
        return 0;

    vector<vector<double>> p(diceCount + 1, vector<double>(diceCount + 1));
    p[0][0] = 1;

    for (int dice = 1; dice <= diceCount; dice++) {
        p[dice][0] = p[dice - 1][0] * (sideCount - 1.0) / sideCount;
        for (int score = 1; score <= dice; score++)
            p[dice][score] = p[dice - 1][score] * (sideCount - 1) / sideCount + p[dice - 1][score - 1] / sideCount;
    }

    double res = 0;
    for (int score = diceCount / 5 + 1; score <= diceCount; score++)
        res += p[diceCount][score];

    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
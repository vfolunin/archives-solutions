#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getP(int gameCount, int winLimit, double winProb, vector<vector<double>> &memo) {
    double &res = memo[gameCount][winLimit];
    if (res != -1)
        return res;

    if (winLimit >= gameCount)
        return res = 1;

    res = 0;

    double p = 1 - winProb;
    for (int wins = 0; wins <= winLimit && wins + 1 <= gameCount; wins++) {
        res += p * getP(gameCount - wins - 1, winLimit, winProb, memo);
        p *= winProb;
    }

    return res;
}

bool solve() {
    int gameCount;
    double winProb;
    cin >> gameCount >> winProb;

    if (!gameCount)
        return 0;

    double res = 0;
    vector<vector<double>> memo(gameCount + 1, vector<double>(gameCount + 1, -1));

    for (int streak = 1; streak <= gameCount; streak++)
        res += streak * (getP(gameCount, streak, winProb, memo) - getP(gameCount, streak - 1, winProb, memo));
    
    cout.precision(6);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
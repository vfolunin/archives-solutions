#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> &time, vector<int> &boost, int i, int boosts, vector<vector<int>> &memo) {
    if (i == time.size())
        return 0;
    
    if (memo[i][boosts] != -1)
        return memo[i][boosts];
    
    int &res = memo[i][boosts];

    int nextBoosts = min<int>(time.size() - 1, boosts + boost[i]);
    res = time[i] + rec(time, boost, i + 1, nextBoosts, memo);

    if (boosts) {
        int nextBoosts = min<int>(time.size() - 1, boosts + boost[i] - 1);
        res = min(res, time[i] / 2 + rec(time, boost, i + 1, nextBoosts, memo));
    }

    return res;
}

bool solve() {
    int tripCount;
    cin >> tripCount;

    if (!tripCount)
        return 0;

    vector<int> time(tripCount), bonus(tripCount);
    for (int i = 0; i < tripCount; i++)
        cin >> time[i] >> bonus[i];

    vector<vector<int>> memo(tripCount, vector<int>(tripCount, -1));

    cout << rec(time, bonus, 0, 0, memo) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
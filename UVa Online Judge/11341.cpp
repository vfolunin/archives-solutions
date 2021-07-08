#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int exam, int hours, vector<vector<pair<bool, int>>> &memo, vector<vector<int>> &mark) {
    if (hours <= 0)
        return -1e9;

    auto &[ready, res] = memo[exam][hours];
    if (ready)
        return res;

    ready = 1;
    res = -1e9;

    if (!exam)
        return res = (mark[exam][hours] >= 5 ? mark[exam][hours] : -1e9);

    for (int lastHours = 1; lastHours <= hours; lastHours++)
        if (mark[exam][lastHours] >= 5)
            res = max(res, rec(exam - 1, hours - lastHours, memo, mark) + mark[exam][lastHours]);
    return res;
}

void solve() {
    int examCount, hourCount;
    cin >> examCount >> hourCount;

    vector<vector<int>> mark(examCount, vector<int>(hourCount + 1));
    for (int exam = 0; exam < examCount; exam++)
        for (int hours = 1; hours <= hourCount; hours++)
            cin >> mark[exam][hours];
    
    vector<vector<pair<bool, int>>> memo(examCount, vector<pair<bool, int>>(hourCount + 1));
    double res = rec(examCount - 1, hourCount, memo, mark) + 1e-9;
    res /= examCount;

    if (res > 0) {
        cout.precision(2);
        cout << "Maximal possible average mark - " << fixed << res << ".\n";
    } else {
        cout << "Peter, you shouldn't have played billiard that much.\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &serverTime, int taskCount, long long timeLimit) {
    long long curCount = 0;
    for (int time : serverTime)
        curCount += timeLimit / time;
    return curCount >= taskCount;
}

void solve() {
    int serverCount, taskCount;
    cin >> serverCount >> taskCount;

    vector<int> serverTime(serverCount);
    for (int &time : serverTime)
        cin >> time;

    long long l = 0, r = 1;
    while (!can(serverTime, taskCount, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(serverTime, taskCount, m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
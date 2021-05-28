#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int setCount, stickCount;
    cin >> setCount >> stickCount;
    setCount += 8;

    vector<int> len(stickCount);
    for (int &l : len)
        cin >> l;
    sort(len.rbegin(), len.rend());

    vector<vector<int>> cost(setCount + 1, vector<int>(stickCount, 1 << 30));
    fill(cost[0].begin(), cost[0].end(), 0);

    for (int sets = 1; sets <= setCount; sets++)
        for (int i = sets * 3 - 1; i < stickCount; i++)
            cost[sets][i] = min(cost[sets][i - 1], cost[sets - 1][i - 2] + (len[i] - len[i - 1]) * (len[i] - len[i - 1]));

    cout << cost[setCount][stickCount - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
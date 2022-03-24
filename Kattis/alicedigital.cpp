#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

void solve() {
    int size, targetValue;
    cin >> size >> targetValue;

    vector<int> p(size), targetPos, underTargetPos = { -1 };
    for (int i = 0; i < size; i++) {
        cin >> p[i];
        if (p[i] == targetValue)
            targetPos.push_back(i);
        if (p[i] <= targetValue)
            underTargetPos.push_back(i);
        if (i)
            p[i] += p[i - 1];
    }
    underTargetPos.push_back(size);

    int maxSum = 0;
    for (int pos : targetPos) {
        int l = *prev(lower_bound(underTargetPos.begin(), underTargetPos.end(), pos));
        int r = *upper_bound(underTargetPos.begin(), underTargetPos.end(), pos);
        maxSum = max(maxSum, getSum(p, l + 1, r - 1));
    }

    cout << maxSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
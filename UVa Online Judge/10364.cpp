#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(vector<int> &masks, int from, int takenCount, int takenMask, vector<int> &memo) {
    if (memo[takenMask])
        return 0;
    if (takenCount == 4)
        return 1;
    for (int i = from; i < masks.size(); i++)
        if (!(takenMask & masks[i]) && rec(masks, i + 1, takenCount + 1, takenMask | masks[i], memo))
            return 1;
    memo[takenMask] = 1;
    return 0;
}

void solve() {
    int stickCount;
    cin >> stickCount;

    int sum = 0;
    vector<int> len(stickCount);
    for (int &x : len) {
        cin >> x;
        sum += x;
    }

    if (sum % 4) {
        cout << "no\n";
        return;
    }
    sum /= 4;

    vector<int> masks;
    for (int mask = 0; mask < (1 << stickCount); mask++) {
        int maskSum = 0;
        for (int bit = 0; bit < stickCount; bit++)
            if (mask & (1 << bit))
                maskSum += len[bit];
        if (maskSum == sum)
            masks.push_back(mask);
    }

    vector<int> memo(1 << stickCount);
    cout << (rec(masks, 0, 0, 0, memo) ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
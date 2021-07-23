#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int encode(vector<int> &items) {
    int mask = 0;
    for (int i = 5; i >= 0; i--)
        mask = mask * 10 + items[i];
    return mask;
}

vector<int> decode(int mask) {
    vector<int> items(6);
    for (int i = 0; i < 6; i++, mask /= 10)
        items[i] = mask % 10;
    return items;
}

bool solve() {
    int itemCount;
    if (!(cin >> itemCount))
        return 0;

    vector<int> itemPrice(6);
    for (int i = 0; i < itemCount; i++)
        cin >> itemPrice[i];

    int comboCount;
    cin >> comboCount;

    vector<vector<int>> combo(comboCount, vector<int>(6));
    vector<int> comboPrice(comboCount);
    for (int i = 0; i < comboCount; i++) {
        for (int j = 0; j < itemCount; j++)
            cin >> combo[i][j];
        cin >> comboPrice[i];
    }

    vector<int> cost(1e6, 1e9);
    cost[0] = 0;

    for (int mask = 0; mask < 1e6; mask++) {
        vector<int> items = decode(mask);
        
        for (int i = 0; i < itemCount; i++) {
            if (items[i]) {
                items[i]--;
                cost[mask] = min(cost[mask], cost[encode(items)] + itemPrice[i]);
                items[i]++;
            }
        }

        for (int i = 0; i < comboCount; i++) {
            int ok = 1;
            for (int j = 0; ok && j < itemCount; j++)
                ok &= items[j] >= combo[i][j];

            if (!ok)
                continue;

            for (int j = 0; j < itemCount; j++)
                items[j] -= combo[i][j];
            cost[mask] = min(cost[mask], cost[encode(items)] + comboPrice[i]);
            for (int j = 0; j < itemCount; j++)
                items[j] += combo[i][j];
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        vector<int> items(6);
        for (int j = 0; j < itemCount; j++)
            cin >> items[j];

        cout << cost[encode(items)] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}
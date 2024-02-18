#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<pair<int, int>> &pairs, int day, vector<int> &used) {
    if (day == pairs.size())
        return 0;

    int res = 0;
    for (int i = 0; i < pairs.size(); i++) {
        if (!used[i] && pairs[i].first > day) {
            used[i] = 1;
            res = max(res, (pairs[i].first - day) * pairs[i].second + rec(pairs, day + 1, used));
            used[i] = 0;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pairCount;
    cin >> pairCount;

    vector<pair<int, int>> pairs(pairCount);
    for (auto &[time, price] : pairs)
        cin >> time >> price;

    vector<int> used(pairs.size());

    cout << rec(pairs, 0, used);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<long long> &a, int i, vector<vector<int>> &side, vector<long long> &sum) {
    if (i == a.size()) {
        if (sum[0] == sum[1]) {
            for (vector<int> &side : side)
                for (int j = 0; j < side.size(); j++)
                    cout << side[j] << (j + 1 < side.size() ? " " : "\n");
            exit(0);
        }
        return;
    }

    rec(a, i + 1, side, sum);

    side[0].push_back(a[i]);
    sum[0] += a[i];
    rec(a, i + 1, side, sum);
    side[0].pop_back();
    sum[0] -= a[i];

    side[1].push_back(a[i]);
    sum[1] += a[i];
    rec(a, i + 1, side, sum);
    side[1].pop_back();
    sum[1] -= a[i];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<long long> a(3);
    for (long long &value : a)
        cin >> value;

    vector<vector<int>> side(2);
    vector<long long> sum(2);
    cin >> sum[0];
    side[0].push_back(sum[0]);

    rec(a, 0, side, sum);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long getSum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

void print(vector<vector<int>> &bestM, int l, int r, string &s) {
    if (l == r) {
        cout << s << "\n";
        return;
    }
    s.push_back('0');
    print(bestM, l, bestM[l][r], s);
    s.back() = '1';
    print(bestM, bestM[l][r] + 1, r, s);
    s.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    vector<vector<long long>> cost(p.size(), vector<long long>(p.size()));
    vector<vector<int>> bestM(p.size(), vector<int>(p.size(), -1));

    for (int len = 2; len <= p.size(); len++) {
        for (int l = 0, r = len - 1; r < p.size(); l++, r++) {
            cost[l][r] = 1e18;

            int ml = len == 2 ? l : bestM[l][r - 1];
            int mr = len == 2 ? r - 1 : bestM[l + 1][r];

            for (int m = ml; m <= mr; m++) {
                if (cost[l][r] > cost[l][m] + cost[m + 1][r]) {
                    cost[l][r] = cost[l][m] + cost[m + 1][r];
                    bestM[l][r] = m;
                }
            }

            cost[l][r] += getSum(p, l, r);
        }
    }

    string s;
    print(bestM, 0, p.size() - 1, s);
}
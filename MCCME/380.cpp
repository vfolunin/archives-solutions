#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> rec(int a, int b, int sum, vector<int> &sums, vector<vector<vector<pair<int, int>>>> &memo) {
    pair<int, int> &res = memo[a][b][sum];
    if (res.first != -1)
        return res;

    if (!a)
        return res = { 0, b + sum };
    if (!b)
        return res = { a + sum, 0 };

    for (int count = 1; count <= a; count++) {
        int nextSum = sum + count, bonus = 0;
        if (binary_search(sums.begin(), sums.end(), nextSum)) {
            bonus = nextSum - 1;
            nextSum = 0;
        }

        auto [bRes, aRes] = rec(b, a - count + bonus, nextSum, sums, memo);
        if (res.first < aRes || res.first == aRes && res.second > bRes)
            res = { aRes, bRes };
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, sumCount;
    cin >> a >> b >> sumCount;

    vector<int> sums(sumCount);
    for (int &sum : sums)
        cin >> sum;

    vector<vector<vector<pair<int, int>>>> memo(101, vector<vector<pair<int, int>>>(101, vector<pair<int, int>>(101, { -1, -1 })));
    cout << rec(a, b, 0, sums, memo).first;
}
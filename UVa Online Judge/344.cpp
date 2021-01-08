#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> roman(int n) {
    static map<int, vector<int>> m = {
        {1, {1, 0, 0, 0, 0}},
        {4, {1, 1, 0, 0, 0}},
        {5, {0, 1, 0, 0, 0}},
        {9, {1, 0, 1, 0, 0}},
        {10, {0, 0, 1, 0, 0}},
        {40, {0, 0, 1, 1, 0}},
        {50, {0, 0, 0, 1, 0}},
        {90, {0, 0, 1, 0, 1}},
        {100, {0, 0, 0, 0, 1}}
    };
    vector<int> res(5);
    while (n) {
        auto &[val, part] = *--m.upper_bound(n);
        for (int i = 0; i < 5; i++)
            res[i] += part[i];
        n -= val;
    }
    return res;
}

vector<vector<int>> answer(101, vector<int>(5));

void prepare() {
    for (int i = 1; i <= 100; i++) {
        vector<int> part = roman(i);
        for (int j = 0; j < 5; j++)
            answer[i][j] = answer[i - 1][j] + part[j];
    }
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << n << ": ";
    cout << answer[n][0] << " i, ";
    cout << answer[n][1] << " v, ";
    cout << answer[n][2] << " x, ";
    cout << answer[n][3] << " l, ";
    cout << answer[n][4] << " c\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    prepare();
    while (solve());
}
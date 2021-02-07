#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<long long, long long>> prepare() {
    vector<pair<long long, long long>> res = { {0, 1} };
    while (res.back().first < 1e10)
        res.push_back({ res.back().second, res.back().first + res.back().second + 1 });
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    static vector<pair<long long, long long>> res = prepare();

    cout << res[n].first << " " << res[n].second << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
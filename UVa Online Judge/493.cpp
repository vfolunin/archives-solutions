#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void tryAdd(vector<pair<int, int>> &res, set<pair<int, int>> &s, int x, int y) {
    if (!x)
        return;
    int d = gcd(x, y);
    x /= d;
    y /= d;
    if (x < 0) {
        x = -x;
        y = -y;
    }
    if (!s.count({ x, y })) {
        s.insert({ x, y });
        res.push_back({ x, y });
    }
}

vector<pair<int, int>> prepare() {
    vector<pair<int, int>> res;
    set<pair<int, int>> s;

    int x = 0, y = 0;
    tryAdd(res, s, x, y);

    const int N = 1e6;

    for (int size = 2; res.size() < N; size += 2) {
        tryAdd(res, s, x, ++y);
        for (int i = 0; res.size() < N && i < size - 1; i++)
            tryAdd(res, s, ++x, y);
        for (int i = 0; res.size() < N && i < size; i++)
            tryAdd(res, s, x, --y);
        for (int i = 0; res.size() < N && i < size; i++)
            tryAdd(res, s, --x, y);
        for (int i = 0; res.size() < N && i < size; i++)
            tryAdd(res, s, x, ++y);
    }

    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<pair<int, int>> res = prepare();

    cout << res[n].second << " / " << res[n].first << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
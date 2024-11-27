#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> rotate(vector<int> &xs) {
    vector<int> res(xs.size());
    for (int y = 0; y < xs.size(); y++)
        res[xs[y]] = xs.size() - 1 - y;
    return res;
}

vector<int> flip(vector<int> &xs) {
    vector<int> res(xs.size());
    for (int y = 0; y < xs.size(); y++)
        res[y] = xs.size() - 1 - xs[y];
    return res;
}

vector<int> getMinXs(vector<int> xs) {
    vector<int> res = xs;

    for (int i = 0; i < 4; i++) {
        xs = rotate(xs);
        res = min(res, xs);
    }

    xs = flip(xs);

    for (int i = 0; i < 4; i++) {
        xs = rotate(xs);
        res = min(res, xs);
    }

    return res;
}

void rec(int y, vector<int> &col, vector<int> &d1, vector<int> &d2, vector<int> &xs, set<vector<int>> &res) {
    if (y == col.size()) {
        res.insert(getMinXs(xs));
        return;
    }

    for (int x = 0; x < col.size(); x++) {
        if (col[x] || d1[y + x] || d2[y - x + col.size()])
            continue;

        col[x] = d1[y + x] = d2[y - x + col.size()] = 1;
        xs.push_back(x);
        rec(y + 1, col, d1, d2, xs, res);
        col[x] = d1[y + x] = d2[y - x + col.size()] = 0;
        xs.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> col(size), d1(size * 2), d2(size * 2), xs;
    set<vector<int>> res;
    rec(0, col, d1, d2, xs, res);

    cout << res.size();
}
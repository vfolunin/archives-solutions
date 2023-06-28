#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> rotate(vector<int> &xs) {
    int size = xs.size();
    vector<int> res(size);
    for (int y = 0; y < size; y++)
        res[xs[y]] = size - 1 - y;
    return res;
}

vector<int> minRotation(vector<int> xs) {
    vector<int> res = xs;
    for (int i = 0; i < 4; i++) {
        res = min(res, xs);
        xs = rotate(xs);
    }
    reverse(xs.begin(), xs.end());
    for (int i = 0; i < 4; i++) {
        res = min(res, xs);
        xs = rotate(xs);
    }
    return res;
}

void rec(int y, vector<int> &col, vector<int> &d1, vector<int> &d2, vector<int> &xs, set<vector<int>> &res) {
    if (y == col.size())
        res.insert(minRotation(xs));

    for (int x = 0; x < col.size(); x++) {
        if (col[x] || d1[y + x] || d2[y - x + col.size()])
            continue;

        col[x] = d1[y + x] = d2[y - x + col.size()] = 1;
        xs[y] = x;
        rec(y + 1, col, d1, d2, xs, res);
        col[x] = d1[y + x] = d2[y - x + col.size()] = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> col(size), d1(size * 2), d2(size * 2), xs(size);
    set<vector<int>> res;
    rec(0, col, d1, d2, xs, res);

    cout << res.size();
}
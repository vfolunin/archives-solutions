#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void makeMove(int na, int nb, const string &s,
    int a, int b, vector<vector<int>> &pa, vector<vector<int>> &pb, vector<vector<string>> &ps, queue<int> &q) {
    if (pa[na][nb] == -1) {
        pa[na][nb] = a;
        pb[na][nb] = b;
        ps[na][nb] = s;
        q.push(na);
        q.push(nb);
    }
}

bool solve() {
    int ca, cb, bn;
    if (!(cin >> ca >> cb >> bn))
        return 0;

    vector<vector<int>> pa(1001, vector<int>(1001, -1));
    vector<vector<int>> pb(1001, vector<int>(1001, -1));
    vector<vector<string>> ps(1001, vector<string>(1001));
    queue<int> q;
    q.push(0);
    q.push(0);

    int an;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();

        if (b == bn) {
            an = a;
            break;
        }

        makeMove(ca, b, "fill A", a, b, pa, pb, ps, q);
        makeMove(a, cb, "fill B", a, b, pa, pb, ps, q);
        makeMove(0, b, "empty A", a, b, pa, pb, ps, q);
        makeMove(a, 0, "empty B", a, b, pa, pb, ps, q);
        int d = min(a, cb - b);
        makeMove(a - d, b + d, "pour A B", a, b, pa, pb, ps, q);
        d = min(ca - a, b);
        makeMove(a + d, b - d, "pour B A", a, b, pa, pb, ps, q);
    }

    vector<string> res = { "success" };
    while (an || bn) {
        res.push_back(ps[an][bn]);
        int pan = pa[an][bn];
        int pbn = pb[an][bn];
        an = pan;
        bn = pbn;
    }

    reverse(res.begin(), res.end());
    
    for (string &s : res)
        cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
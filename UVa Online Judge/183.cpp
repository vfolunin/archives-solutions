#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<vector<int>> &p, int y1, int x1, int y2, int x2) {
    int res = p[y2][x2];
    if (y1)
        res -= p[y1 - 1][x2];
    if (x1)
        res -= p[y2][x1 - 1];
    if (y1 && x1)
        res += p[y1 - 1][x1 - 1];
    return res;
}

void recCompress(vector<vector<int>> &p, int y1, int x1, int y2, int x2, string &res) {
    if (y1 > y2 || x1 > x2)
        return;

    int s = sum(p, y1, x1, y2, x2);
    if (s == 0) {
        res += '0';
        return;
    }
    if (s == (y2 - y1 + 1) * (x2 - x1 + 1)) {
        res += '1';
        return;
    }

    res += 'D';
    int ym = y1 + (y2 - y1) / 2;
    int xm = x1 + (x2 - x1) / 2;
    recCompress(p, y1, x1, ym, xm, res);
    recCompress(p, y1, xm + 1, ym, x2, res);
    recCompress(p, ym + 1, x1, y2, xm, res);
    recCompress(p, ym + 1, xm + 1, y2, x2, res);
}

string compress(vector<string> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<int>> p(h, vector<int>(w));

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            p[y][x] = a[y][x] - '0';
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    string res;
    recCompress(p, 0, 0, h - 1, w - 1, res);
    return res;
}

void recDecompress(string &s, int &i, int y1, int x1, int y2, int x2, vector<string> &res) {
    if (y1 > y2 || x1 > x2)
        return;

    if (s[i++] != 'D') {
        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                res[y][x] = s[i - 1];
        return;
    }

    int ym = y1 + (y2 - y1) / 2;
    int xm = x1 + (x2 - x1) / 2;
    recDecompress(s, i, y1, x1, ym, xm, res);
    recDecompress(s, i, y1, xm + 1, ym, x2, res);
    recDecompress(s, i, ym + 1, x1, y2, xm, res);
    recDecompress(s, i, ym + 1, xm + 1, y2, x2, res);    
}

vector<string> decompress(string &s, int h, int w) {
    vector<string> res(h, string(w, ' '));
    int i = 0;
    recDecompress(s, i, 0, 0, h - 1, w - 1, res);
    return res;
}

bool solve() {
    char type;
    int h, w;
    if (!(cin >> type >> h >> w))
        return 0;

    string res;
    if (type == 'B') {
        vector<string> a(h, string(w, ' '));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                cin >> a[y][x];

        res = compress(a);
    } else {
        string s;
        cin >> s;

        vector<string> bitmap = decompress(s, h, w);
        for (string &row : bitmap)
            res += row;
    }

    cout << (type == 'B' ? "D" : "B") << setw(4) << h << setw(4) << w << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 == res.size() || i % 50 == 49)
            cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
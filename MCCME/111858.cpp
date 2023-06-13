#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<int>> &a, int y, int x, string &s, string &res) {
    s.push_back(a[y][x] + '0');

    if (s.size() == 9) {
        res = max(res, s);
    } else {
        a[y][x] = 0;

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx])
                rec(a, ty, tx, s, res);
        }

        a[y][x] = s.back() - '0';
    }

    s.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> a(3, vector<int>(3));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];
    
    string res;
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            string s;
            rec(a, y, x, s, res);
        }
    }
    
    cout << res;
}
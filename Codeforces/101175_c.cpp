#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

set<pair<int, int>> bfs(vector<string> &a, int y, int x, char mark, char find) {
    queue<int> q;
    q.push(y);
    q.push(x);
    char c = a[y][x];
    a[y][x] = mark;

    set<pair<int, int>> finds;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size()) {
                if (a[ty][tx] == c) {
                    q.push(ty);
                    q.push(tx);
                    a[ty][tx] = mark;
                } else if (a[ty][tx] == find) {
                    finds.insert({ ty, tx });
                }
            }
        }
    }

    return finds;
}

void markHole(vector<string> &a, int y, int x) {
    bfs(a, y, x, 'h', '#');
}

char markSymbol(vector<string> &a, int y, int x) {
    set<pair<int, int>> holes = bfs(a, y, x, 's', '0');

    int holeCount = 0;
    for (auto &[hy, hx] : holes) {
        if (a[hy][hx] == '0') {
            holeCount++;
            markHole(a, hy, hx);
        }
    }

    static string codes = "WAKJSD";
    return codes[holeCount];
}

string markFree(vector<string> &a) {
    set<pair<int, int>> symbols = bfs(a, 0, 0, 'f', '1');

    string codes;
    for (auto &[sy, sx] : symbols)
        if (a[sy][sx] == '1')
            codes += markSymbol(a, sy, sx);

    sort(codes.begin(), codes.end());
    return codes;
}

bool solve(int test) {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a;
    a.push_back(string(w * 4 + 2, '0'));

    for (int y = 1; y <= h; y++) {
        a.push_back("0");

        string line;
        cin >> line;

        static string hex = "0123456789abcdef";
        static string bin = "0000000100100011010001010110011110001001101010111100110111101111";

        for (char c : line)
            a.back() += bin.substr(hex.find(c) * 4, 4);

        a.back() += "0";
    }

    a.push_back(string(w * 4 + 2, '0'));

    string res = markFree(a);

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
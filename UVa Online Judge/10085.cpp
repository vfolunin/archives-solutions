#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

const int SIDE = 3;

struct Board {
    vector<int> a;
    int zy, zx;

    bool operator < (const Board &that) const {
        return a < that.a;
    }

    void findZero() {
        for (int y = 0; y < SIDE; y++) {
            for (int x = 0; x < SIDE; x++) {
                if (!a[y * SIDE + x]) {
                    zy = y;
                    zx = x;
                    break;
                }
            }
        }
    }

    bool canMove(int dy, int dx) {
        int ty = zy + dy, tx = zx + dx;
        return 0 <= ty && ty < SIDE && 0 <= tx && tx < SIDE;
    }

    Board move(int dy, int dx) {
        Board res = *this;
        int ty = zy + dy, tx = zx + dx;
        swap(res.a[zy * SIDE + zx], res.a[ty * SIDE + tx]);
        res.findZero();
        return res;
    }
};

istream &operator >> (istream &in, Board &board) {
    board.a.resize(SIDE * SIDE);
    for (int &x : board.a)
        in >> x;
    board.findZero();
    return in;
}

ostream &operator << (ostream &out, const Board &board) {
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            out << board.a[i * SIDE + j] << (j + 1 < SIDE ? " " : "\n");
    return out;
}

pair<Board, string> bfs(Board &start) {
    map<Board, int> pred;
    queue<Board> q;

    pred[start] = -1;
    q.push(start);

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };
    static string dc = "URDL";

    Board v;
    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            if (!v.canMove(dy[d], dx[d]))
                continue;

            Board to = v.move(dy[d], dx[d]);
            if (!pred.count(to)) {
                pred[to] = d;
                q.push(to);
            }
        }
    }

    Board last = v;
    string path;
    while (1) {
        int d = pred[v];
        if (d == -1)
            break;
        path.push_back(dc[d]);
        v = v.move(dy[(d + 2) % 4], dx[(d + 2) % 4]);
    }
    reverse(path.begin(), path.end());

    return { last, path };
}

void solve(int test) {
    Board board;
    cin >> board;

    auto [res, path] = bfs(board);

    cout << "Puzzle #" << test << "\n";
    cout << res << path << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
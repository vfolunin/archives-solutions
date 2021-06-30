#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int SIDE = 4;
const int SIZE = SIDE * SIDE;

struct Board {
    vector<int> a;
    int zy, zx, manhattanHeuristic, unsolvable;

    void recalculate() {
        manhattanHeuristic = 0;
        int inv = 0;
        for (int y = 0; y < SIDE; y++) {
            for (int x = 0; x < SIDE; x++) {
                if (a[y * SIDE + x]) {
                    for (int i = 0; i < y * SIDE + x; i++)
                        inv += a[i] && a[i] > a[y * SIDE + x];
                } else {
                    zy = y;
                    zx = x;
                }
                int tile = (a[y * SIDE + x] + SIZE - 1) % SIZE;
                int ty = tile / SIDE, tx = tile % SIDE;
                manhattanHeuristic += abs(y - ty) + abs(x - tx);
                unsolvable = (inv + zy) % 2 == 0;
            }
        }
    }

    bool operator < (const Board &that) const {
        if (manhattanHeuristic != that.manhattanHeuristic)
            return manhattanHeuristic < that.manhattanHeuristic;
        return a < that.a;
    }

    bool canMove(int dy, int dx) {
        int ty = zy + dy, tx = zx + dx;
        return 0 <= ty && ty < SIDE && 0 <= tx && tx < SIDE;
    }

    Board move(int dy, int dx) {
        Board res = *this;
        int ty = zy + dy, tx = zx + dx;
        swap(res.a[zy * SIDE + zx], res.a[ty * SIDE + tx]);
        res.recalculate();
        return res;
    }
};

istream &operator >> (istream &in, Board &board) {
    board.a.resize(SIZE);
    for (int i = 0; i < SIZE; i++)
        cin >> board.a[i];
    board.recalculate();
    return in;
}

struct Solver {
    map<Board, int> visited, pred;

    static inline vector<int> dy = { -1, 0, 1, 0 };
    static inline vector<int> dx = { 0, 1, 0, -1 };
    static inline string dc = "URDL";

    bool dfs(Board &v, int depth, int limit, int &nextLimit) {
        if (depth + v.manhattanHeuristic > limit) {
            nextLimit = min(nextLimit, depth + v.manhattanHeuristic);
            return 0;
        }

        if (!v.manhattanHeuristic)
            return 1;

        if (auto it = visited.find(v); it != visited.end() && it->second <= depth)
            return 0;
        visited[v] = depth;

        for (int d = 0; d < 4; d++) {
            if (!v.canMove(dy[d], dx[d]))
                continue;

            Board to = v.move(dy[d], dx[d]);
            if (dfs(to, depth + 1, limit, nextLimit)) {
                pred[to] = d;
                return 1;
            }
        }

        return 0;
    }

    string idaStar(Board &board) {
        if (board.unsolvable)
            return "This puzzle is not solvable.";

        int limit = 0;
        while (1) {
            int nextLimit = 1e9;
            visited.clear();
            pred = { { board, -1 } };
   
            if (dfs(board, 0, limit, nextLimit))
                break;

            limit = nextLimit;
        }

        for (int i = 0; i < SIZE; i++)
            board.a[i] = (i + 1) % SIZE;
        board.recalculate();

        string path;
        while (1) {
            int d = pred[board];
            if (d == -1)
                break;
            path.push_back(dc[d]);
            board = board.move(dy[(d + 2) % 4], dx[(d + 2) % 4]);
        }
        reverse(path.begin(), path.end());
        return path;
    }
} solver;

void solve() {
    Board board;
    cin >> board;

    cout << solver.idaStar(board) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Board {
    vector<string> a;
    int zeroY, zeroX;

    Board makeMove(int toY, int toX) const {
        Board res = *this;

        swap(res.a[zeroY][zeroX], res.a[toY][toX]);
        res.zeroY = toY;
        res.zeroX = toX;

        return res;
    }

    bool operator < (const Board &that) const {
        return a < that.a;
    }

    bool isSolved() const {
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a.size(); x++)
                if (a[y][x] != '-' && a[y][x] != y * a.size() + x + '1')
                    return false;
        return true;
    }

    vector<Board> getNeighbors() const {
        vector<Board> neighbors;

        static const vector<int> DY = { -1, 0, 1, 0 };
        static const vector<int> DX = { 0, 1, 0, -1 };

        for (int i = 0; i < DY.size(); i++) {
            int toY = zeroY + DY[i];
            int toX = zeroX + DX[i];

            if (0 <= toY && toY < a.size() && 0 <= toX && toX < a.size())
                neighbors.push_back(makeMove(toY, toX));
        }

        return neighbors;
    }

    friend istream &operator >> (istream &in, Board &board) {
        board.a.resize(2);

        for (int y = 0; y < board.a.size(); y++) {
            cin >> board.a[y];

            for (int x = 0; x < board.a.size(); x++) {
                if (board.a[y][x] == '-') {
                    board.zeroY = y;
                    board.zeroX = x;
                }
            }
        }

        return in;
    }
};

int bfs(const Board &start) {
    map<Board, int> dist;
    queue<Board> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        Board v = q.front();
        q.pop();

        if (v.isSolved())
            return dist[v];

        for (Board &to : v.getNeighbors()) {
            if (!dist.count(to) || dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Board board;
    cin >> board;

    cout << bfs(board);
}

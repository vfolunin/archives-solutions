#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Cube {
    int top = 0, bottom = 0, left = 0, right = 0, front = 0, back = 0;

    Cube() {}

    Cube(int mask) {
        top = mask & 1;
        bottom = (mask >> 1) & 1;
        left = (mask >> 2) & 1;
        right = (mask >> 3) & 1;
        front = (mask >> 4) & 1;
        back = (mask >> 5) & 1;
    }

    int mask() {
        int res = top;
        res |= bottom << 1;
        res |= left << 2;
        res |= right << 3;
        res |= front << 4;
        res |= back << 5;
        return res;
    }

    void rotateD(int &a, int &b, int &c, int &d) {
        swap(a, b);
        swap(b, c);
        swap(c, d);
    }

    void rotateLeft() {
        rotateD(top, right, bottom, left);
    }

    void rotateRight() {
        rotateD(top, left, bottom, right);
    }

    void rotateFront() {
        rotateD(top, back, bottom, front);
    }

    void rotateBack() {
        rotateD(top, front, bottom, back);
    }

    bool final() {
        return top && bottom && left && right && front && back;
    }
};

struct State {
    vector<vector<int>> board;
    int y, x;
    Cube cube;

    State() : board(4, vector<int>(4)) {}

    State(int mask) {
        board.assign(4, vector<int>(4));
        for (int i = 3; i >= 0; i--) {
            for (int j = 3; j >= 0; j--) {
                board[i][j] = mask & 1;
                mask >>= 1;
            }
        }

        y = mask & 3;
        mask >>= 2;
        x = mask & 3;
        mask >>= 2;

        cube = Cube(mask);
    }

    int mask() {
        int res = cube.mask();

        res <<= 2;
        res |= x;
        res <<= 2;
        res |= y;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                res <<= 1;
                res |= board[i][j];
            }
        }

        return res;
    }

    vector<int> neighbors() {
        vector<int> res;

        if (y) {
            State n = *this;
            n.y--;
            n.cube.rotateBack();
            if (n.cube.bottom ^ n.board[n.y][n.x])
                swap(n.cube.bottom, n.board[n.y][n.x]);
            res.push_back(n.mask());
        }
        if (y < 3) {
            State n = *this;
            n.y++;
            n.cube.rotateFront();
            if (n.cube.bottom ^ n.board[n.y][n.x])
                swap(n.cube.bottom, n.board[n.y][n.x]);
            res.push_back(n.mask());
        }
        if (x) {
            State n = *this;
            n.x--;
            n.cube.rotateLeft();
            if (n.cube.bottom ^ n.board[n.y][n.x])
                swap(n.cube.bottom, n.board[n.y][n.x]);
            res.push_back(n.mask());
        }
        if (x < 3) {
            State n = *this;
            n.x++;
            n.cube.rotateRight();
            if (n.cube.bottom ^ n.board[n.y][n.x])
                swap(n.cube.bottom, n.board[n.y][n.x]);
            res.push_back(n.mask());
        }

        return res;
    }

    void print() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == y && j == x)
                    cout << 'D';
                else
                    cout << (board[i][j] ? 'X' : '.');
            }
            cout << "\n";
        }
        cout << "TBLRFB\n";
        cout << cube.top << cube.bottom << cube.left << cube.right << cube.front << cube.back << "\n";
    }
};

int bfs(int start) {
    vector<int> dist(1 << 26, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int vMask = q.front();
        q.pop();

        State v(vMask);

        //v.print();
        //cout << dist[vMask] << "\n";
        //char c;
        //cin >> c;

        if (v.cube.final())
            return dist[vMask];

        for (int toMask : v.neighbors()) {
            if (dist[toMask] == -1) {
                dist[toMask] = dist[vMask] + 1;
                q.push(toMask);
            }
        }
    }

    return -1;
}

void solve() {
    State state;

    vector<string> a(4);
    for (int y = 0; y < 4; y++) {
        cin >> a[y];
        for (int x = 0; x < 4; x++) {
            if (a[y][x] == 'X')
                state.board[y][x] = 1;
            if (a[y][x] == 'D') {
                state.y = y;
                state.x = x;
            }
        }
    }

    int res = bfs(state.mask());

    if (res != -1)
        cout << res << "\n";
    else
        cout << "impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
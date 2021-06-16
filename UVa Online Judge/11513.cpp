#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

struct Solver {
    unordered_map<int, int> pred, move;

    int hShift(int n, int i) {
        string s = to_string(n);
        int t = s[i * 3];
        s[i * 3] = s[i * 3 + 1];
        s[i * 3 + 1] = s[i * 3 + 2];
        s[i * 3 + 2] = t;
        return stoi(s);
    }

    int vShift(int n, int j) {
        string s = to_string(n);
        int t = s[j];
        s[j] = s[6 + j];
        s[6 + j] = s[3 + j];
        s[3 + j] = t;
        return stoi(s);
    }

    string toString(int move) {
        return (move < 3 ? "H" : "V") + to_string(move % 3 + 1);
    }

    void bfs() {
        queue<int> q;

        pred[123456789] = -1;
        move[123456789] = -1;
        q.push(123456789);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            vector<int> to = { hShift(v, 0), hShift(v, 1), hShift(v, 2), vShift(v, 0), vShift(v, 1), vShift(v, 2) };
            for (int i = 0; i < to.size(); i++) {
                if (!pred.count(to[i])) {
                    pred[to[i]] = v;
                    move[to[i]] = i;
                    q.push(to[i]);
                }
            }
        }
    }

    string getPath(int v) {
        if (!pred.count(v))
            return "Not solvable";

        string path;
        for (; v != 123456789; v = pred[v])
            path += toString(move[v]);
        return to_string(path.size() / 2) + " " + path;
    }
};

bool solve(Solver &solver) {
    int v = 0;
    for (int i = 0; i < 9; i++) {
        int x;
        if (!(cin >> x))
            return 0;
        v = v * 10 + x;
    }

    cout << solver.getPath(v) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solver solver;
    solver.bfs();

    while (solve(solver));
}
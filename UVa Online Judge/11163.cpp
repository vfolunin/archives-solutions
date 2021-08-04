#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    static inline vector<vector<int>> dx = {
        {-4, 1, 3, 4},
        {-4, -1, 1, 4},
        {-4, -1, 1, 4},
        {-4, -3, -1, 4}
    };
    vector<vector<int>> cost;

    Solver() {
        cost.assign(40, vector<int>(40, 1e9));

        for (int v = 0; v < cost.size(); v++)
            cost[v][v] = 0;

        for (int a = 0; a < cost.size(); a++) {
            for (int d = 0; d < 4; d++) {
                int b = a + dx[a % 4][d];
                if (0 <= b && b < cost.size())
                    cost[a][b] = 1;
            }
        }

        for (int v = 0; v < cost.size(); v++)
            for (int a = 0; a < cost.size(); a++)
                for (int b = 0; b < cost.size(); b++)
                    cost[a][b] = min(cost[a][b], cost[a][v] + cost[v][b]);
    }

    vector<int> target;
    map<vector<int>, int> dist;

    bool dfs(int depth, int limit, int &nextLimit) {
        int x = 0, h = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i])
                h += cost[i][target[i]];
            else
                x = i;
        }

        if (depth + h > limit) {
            nextLimit = min(nextLimit, depth + h);
            return 0;
        }

        if (!h)
            return 1;

        if (auto it = dist.find(target); it != dist.end() && it->second <= depth)
            return 0;
        dist[target] = depth;

        for (int d = 0; d < 4; d++) {
            int tx = x + dx[x % 4][d];
            if (tx < 0 || tx >= target.size())
                continue;

            swap(target[x], target[tx]);
            if (dfs(depth + 1, limit, nextLimit))
                return 1;
            swap(target[x], target[tx]);
        }

        return 0;
    }

    int idaStar(vector<int> &v) {
        target = v;

        int limit = 0;
        while (1) {
            int nextLimit = 1e9;
            dist.clear();

            if (dfs(0, limit, nextLimit))
                return limit;

            limit = nextLimit;
        }
    }
};

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
        x--;
    }

    static Solver solver;
    int res = solver.idaStar(v);

    cout << "Set " << test << ":\n" << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
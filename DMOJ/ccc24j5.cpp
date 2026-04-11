#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dfs(vector<string> &plan, int y, int x) {
    int res = 0;
    if (plan[y][x] == 'S')
        res++;
    else if (plan[y][x] == 'M')
        res += 5;
    else if (plan[y][x] == 'L')
        res += 10;

    plan[y][x] = '*';

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < plan.size() && 0 <= tx && tx < plan[0].size() && plan[ty][tx] != '*')
            res += dfs(plan, ty, tx);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int height, width;
    cin >> height >> width;

    vector<string> plan(height);
    for (string &row : plan)
        cin >> row;

    int startY, startX;
    cin >> startY >> startX;

    cout << dfs(plan, startY, startX );
}
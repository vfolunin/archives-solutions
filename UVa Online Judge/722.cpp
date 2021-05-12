#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int si, int sj) {
    queue<int> q;
    q.push(si);
    q.push(sj);
    a[si][sj] = '1';

    int res = 1;

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();

        static vector<int> di = { -1, 0, 1, 0 };
        static vector<int> dj = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ti = i + di[d], tj = j + dj[d];
            if (0 <= ti && ti < a.size() && 0 <= tj && tj < a[0].size() && a[ti][tj] == '0') {
                q.push(ti);
                q.push(tj);
                a[ti][tj] = '1';
                res++;
            }
        }
    }

    return res;
}

void solve(int test) {
    int si, sj;
    cin >> si >> sj;
    si--;
    sj--;

    vector<string> a;
    cin.ignore();
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;
        a.push_back(line);
    }

    if (test)
        cout << "\n";
    cout << bfs(a, si, sj) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int i, int j) {
    static const int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static const int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    a[i][j] = '0';

    for (int d = 0; d < 8; d++) {
        int ti = i + di[d], tj = j + dj[d];
        if (0 <= ti && ti < a.size() && 0 <= tj && tj < a.size() && a[ti][tj] == '1')
            dfs(a, ti, tj);
    }
}

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    vector<string> a(n);
    for (string &row : a)
        cin >> row;

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1') {
                res++;
                dfs(a, i, j);
            }
        }
    }

    cout << "Image number " << test << " contains " << res << " war eagles.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (int test = 1; solve(test); test++);
}
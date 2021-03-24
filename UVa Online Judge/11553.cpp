#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int recB(vector<vector<int>> &a, int r, int maskR, int maskC);

vector<vector<int>> ansA;
int recA(vector<vector<int>> &a, int maskR, int maskC) {
    if (ansA[maskR][maskC] != -2e9)
        return ansA[maskR][maskC];

    if (!maskR && !maskC)
        return ansA[maskR][maskC] = 0;

    ansA[maskR][maskC] = -1e9;

    for (int r = 0; r < a.size(); r++) {
        if (!(maskR & (1 << r)))
            continue;
        int recAns = recB(a, r, maskR ^ (1 << r), maskC);
        ansA[maskR][maskC] = max(ansA[maskR][maskC], recAns);
    }

    return ansA[maskR][maskC];
}

vector<vector<vector<int>>> ansB;
int recB(vector<vector<int>> &a, int r, int maskR, int maskC) {
    if (ansB[r][maskR][maskC] != 2e9)
        return ansB[r][maskR][maskC];

    ansB[r][maskR][maskC] = 1e9;

    for (int c = 0; c < a.size(); c++) {
        if (!(maskC & (1 << c)))
            continue;
        int recAns = recA(a, maskR, maskC ^ (1 << c));
        ansB[r][maskR][maskC] = min(ansB[r][maskR][maskC], recAns + a[r][c]);
    }

    return ansB[r][maskR][maskC];
}

void solve() {
    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    ansA.assign(1 << size, vector<int>(1 << size, -2e9));
    ansB.assign(size, vector<vector<int>>(1 << size, vector<int>(1 << size, 2e9)));
    cout << recA(a, (1 << size) - 1, (1 << size) - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
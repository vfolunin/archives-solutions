#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int getCost(vector<string> &a, int &rowMask) {
    int colMask = 0;
    for (int i = 0; i < a.size(); i++) {
        if (rowMask & (1 << i))
            continue;
        for (int j = 0; j < a.size(); j++)
            if (a[i][j] == '#')
                colMask |= 1 << j;
    }
    return max(ones(rowMask), ones(colMask));
}

bool solve() {
    vector<string> a(15);
    for (string &row : a)
        if (!(cin >> row))
            return 0;

    int res = a.size();
    for (int rowMask = 0; rowMask < (1 << a.size()); rowMask++)
        res = min(res, getCost(a, rowMask));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
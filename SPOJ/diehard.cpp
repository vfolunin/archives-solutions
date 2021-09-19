#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int hp, int ap, int land) {
    if (hp <= 0 || ap <= 0)
        return -1;

    static vector<vector<vector<int>>> memo(2000, vector<vector<int>>(2000, vector<int>(3, -1)));
    int &res = memo[hp][ap][land];
    if (res != -1)
        return res;

    if (land == 0) {
        hp += 3;
        ap += 2;
        return res = 1 + max(rec(hp, ap, 1), rec(hp, ap, 2));
    } else if (land == 1) {
        hp -= 5;
        ap -= 10;
        return res = 1 + max(rec(hp, ap, 0), rec(hp, ap, 2));
    } else {
        hp -= 20;
        ap += 5;
        return res = 1 + max(rec(hp, ap, 0), rec(hp, ap, 1));
    }
}

void solve() {
    int hp, ap;
    cin >> hp >> ap;

    int res = 0;
    for (int land = 0; land < 3; land++)
        res = max(res, rec(hp, ap, land));

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
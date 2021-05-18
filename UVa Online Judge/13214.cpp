#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> getC() {
    vector<vector<long long>> c(51, vector<long long>(51));
    for (int i = 0; i < c.size(); i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
    }
    return c;
}

void solve() {
    int h, w;
    cin >> h >> w;

    static vector<vector<long long>> c = getC();

    cout << c[h + w - 2][h - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
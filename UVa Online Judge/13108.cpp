#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> getC() {
    vector<vector<long long>> c(201, vector<long long>(201));
    for (int i = 0; i < 201; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    n--;

    static vector<vector<long long>> c = getC();
    cout << c[n][0] + c[n][1] + c[n][2] + c[n][3] + c[n][4] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int k0, int k1, int k2) {
    static vector<vector<vector<int>>> res(2, vector<vector<int>>(1001, vector<int>(1001)));
    if (res[k0][k1][k2])
        return res[k0][k1][k2];

    if (k0 && (k1 + 2 * k2) % 3 == 0 && rec(0, k1, k2) == 2)
        return res[k0][k1][k2] = 1;
    if (k1 && (k1 - 1 + 2 * k2) % 3 == 0 && rec(k0, k1 - 1, k2) == 2)
        return res[k0][k1][k2] = 1;
    if (k2 && (k1 + 2 * (k2 - 1)) % 3 == 0 && rec(k0, k1, k2 - 1) == 2)
        return res[k0][k1][k2] = 1;
    return res[k0][k1][k2] = 2;
}

void solve(int test) {
    string s;
    cin >> s;

    int k[3] = {};
    for (char c : s)
        k[(c - '0') % 3]++;
    
    int res = rec(k[0] % 2, k[1], k[2]);

    cout << "Case " << test << ": " << (res == 1 ? "S\n" : "T\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
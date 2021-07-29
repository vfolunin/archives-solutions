#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int MOD = 10007;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    vector<vector<vector<int>>> ways(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1)));
    vector<vector<vector<int>>> waysA(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1)));
    vector<vector<vector<int>>> waysB(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1)));

    for (int ai = 0; ai <= a.size(); ai++)
        for (int bi = 0; bi <= b.size(); bi++)
            ways[ai][bi][0] = waysA[ai][bi][0] = waysB[ai][bi][0] = 1;

    for (int ai = 0; ai <= a.size(); ai++) {
        for (int bi = 0; bi <= b.size(); bi++) {
            for (int ci = 1; ci <= c.size(); ci++) {
                if (ai) {
                    waysA[ai][bi][ci] = waysA[ai - 1][bi][ci];
                    if (a[ai - 1] == c[ci - 1])
                        waysA[ai][bi][ci] = (waysA[ai][bi][ci] + ways[ai - 1][bi][ci - 1]) % MOD;
                }
                if (bi) {
                    waysB[ai][bi][ci] = waysB[ai][bi - 1][ci];
                    if (b[bi - 1] == c[ci - 1])
                        waysB[ai][bi][ci] = (waysB[ai][bi][ci] + ways[ai][bi - 1][ci - 1]) % MOD;
                }
                ways[ai][bi][ci] = (waysA[ai][bi][ci] + waysB[ai][bi][ci]) % MOD;
            }
        }
    }

    cout << ways[a.size()][b.size()][c.size()] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    vector<vector<int>> len(a.size() + 1, vector<int>(b.size() + 1));
    vector<vector<long long>> ways(a.size() + 1, vector<long long>(b.size() + 1));

    for (int ai = 0; ai <= a.size(); ai++)
        ways[ai][0] = 1;
    for (int bi = 1; bi <= b.size(); bi++)
        ways[0][bi] = 1;

    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1]) {
                len[ai][bi] = len[ai - 1][bi - 1] + 1;
                ways[ai][bi] += ways[ai - 1][bi - 1];
            } else {
                len[ai][bi] = max(len[ai - 1][bi], len[ai][bi - 1]);
                if (len[ai][bi] == len[ai - 1][bi])
                    ways[ai][bi] += ways[ai - 1][bi];
                if (len[ai][bi] == len[ai][bi - 1])
                    ways[ai][bi] += ways[ai][bi - 1];
            }
        }
    }

    cout << "Case #" << test << ": ";
    cout << a.size() + b.size() - len[a.size()][b.size()] << " ";
    cout << ways[a.size()][b.size()] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}
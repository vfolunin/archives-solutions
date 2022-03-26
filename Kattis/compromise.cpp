#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<int> sum(w);

    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < w; j++)
            sum[j] += row[j] - '0';
    }

    for (int i = 0; i < w; i++)
        cout << (sum[i] * 2 > h ? "1" : "0");
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
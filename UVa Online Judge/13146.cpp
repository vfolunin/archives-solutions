#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int editDistance(string &a, string &b) {
    vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));

    for (int na = 1; na <= a.size(); na++)
        dist[na][0] = na;
    for (int nb = 1; nb <= b.size(); nb++)
        dist[0][nb] = nb;

    for (int na = 1; na <= a.size(); na++) {
        for (int nb = 1; nb <= b.size(); nb++) {
            if (a[na - 1] == b[nb - 1])
                dist[na][nb] = dist[na - 1][nb - 1];
            else
                dist[na][nb] = 1 + min(dist[na - 1][nb - 1], min(dist[na - 1][nb], dist[na][nb - 1]));
        }
    }

    return dist[a.size()][b.size()];
}

void solve() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << editDistance(a, b) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}
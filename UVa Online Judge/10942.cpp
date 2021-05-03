#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100;
}

int daysInMonth(int m, int y) {
    vector<int> days = { 0, 31, 28 + isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}

void solve() {
    long long century;
    vector<int> p(3);
    cin >> century >> p[0] >> p[1] >> p[2];
    century %= 4;

    vector<int> res(3, 1e9);
    sort(p.begin(), p.end());
    do {
        if (1 <= p[1] && p[1] <= 12 && 1 <= p[2] && p[2] <= daysInMonth(p[1], century * 100 + p[0]))
            res = min(res, p);
    } while (next_permutation(p.begin(), p.end()));

    if (res[0] == 1e9)
        cout << "-1\n";
    else
        for (int i = 0; i < 3; i++)
            cout << setw(2) << setfill('0') << res[i] << (i < 2 ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
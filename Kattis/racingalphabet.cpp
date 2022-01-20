#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int pos(char c) {
    if (c == ' ')
        return 26;
    if (c == '\'')
        return 27;
    return c - 'A';
}

int dist(char a, char b) {
    int res = abs(pos(a) - pos(b));
    return min(res, 28 - res);
}

void solve() {
    string text;
    getline(cin, text);

    double unitTime = acos(-1) * 60 / 28 / 15;

    double res = 1;
    for (int i = 1; i < text.size(); i++)
        res += dist(text[i - 1], text[i]) * unitTime + 1;

    cout << fixed << res << "\n";
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
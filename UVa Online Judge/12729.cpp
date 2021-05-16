#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w;
    cin >> h >> w;

    int evenH = h - h % 2, evenW = w - w % 2, moves = evenH * evenW / 4;
    int a = (moves + 1) / 2 * 4, b = h * w - a;

    cout << "Case #" << test << ": ";
    if (a > b)
        cout << "Ana\n";
    else if (a == b)
        cout << "Draw\n";
    else
        cout << "Bob\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
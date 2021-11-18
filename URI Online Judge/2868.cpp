#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b, c;
    char op, eq;
    cin >> a >> op >> b >> eq >> c;

    int dist = 0;
    if (op == '+')
        dist = abs(a + b - c);
    else if (op == '-')
        dist = abs(a - b - c);
    else
        dist = abs(a * b - c);

    cout << "E" << string(dist, 'r') << "ou!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
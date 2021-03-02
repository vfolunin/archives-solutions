#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    int h, m;
    cin >> h;
    cin.ignore();
    cin >> m;
    return h * 60 + m;
}

void solve(int test) {
    int l1 = readTime(), r1 = readTime();
    int l2 = readTime(), r2 = readTime();

    cout << "Case " << test << ": ";
    if (l1 <= r2 && l2 <= r1)
        cout << "Mrs Meeting\n";
    else
        cout << "Hits Meeting\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
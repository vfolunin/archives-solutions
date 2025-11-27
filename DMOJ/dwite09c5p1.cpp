#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    for (int i = -5; i <= -1; i++)
        cout << (n < 0 && n <= i ? "*" : "-");
    cout << "|";
    for (int i = 1; i <= 5; i++)
        cout << (n > 0 && i <= n ? "*" : "-");
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
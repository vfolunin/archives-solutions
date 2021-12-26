#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int total, used, warn, crit;
    if (!(cin >> total >> used >> warn >> crit))
        return 0;

    if (used * 100 >= crit * total)
        cout << "critical\n";
    else if (used * 100 >= warn * total)
        cout << "warning\n";
    else
        cout << "OK\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
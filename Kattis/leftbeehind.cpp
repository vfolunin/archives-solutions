#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    if (a + b == 13)
        cout << "Never speak again.\n";
    else if (a < b)
        cout << "Left beehind.\n";
    else if (a == b)
        cout << "Undecided.\n";
    else
        cout << "To the convention.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
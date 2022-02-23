#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    if (!a1)
        return 0;

    if (a1 < a2)
        swap(a1, a2);
    if (b1 < b2)
        swap(b1, b2);

    int a = a1 * 10 + a2, b = b1 * 10 + b2;

    if (a == 21 || b == 21) {
        if (a == b)
            cout << "Tie.\n";
        else if (a == 21)
            cout << "Player 1 wins.\n";
        else
            cout << "Player 2 wins.\n";
        return 1;
    }

    if (a1 == a2 || b1 == b2) {
        if (a == b)
            cout << "Tie.\n";
        else if (a1 == a2 && b1 != b2 || a1 == a2 && b1 == b2 && a > b)
            cout << "Player 1 wins.\n";
        else
            cout << "Player 2 wins.\n";
        return 1;
    }

    if (a == b)
        cout << "Tie.\n";
    else if (a > b)
        cout << "Player 1 wins.\n";
    else
        cout << "Player 2 wins.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
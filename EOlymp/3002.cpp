#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int gameCount;
    cin >> gameCount;

    int aWins = 0, bWins = 0;
    for (int i = 0; i < gameCount; i++) {
        int a, b;
        cin >> a >> b;

        aWins += a > b;
        bWins += a < b;
    }

    if (aWins == bWins)
        cout << 0;
    else if (aWins > bWins)
        cout << 1;
    else
        cout << 2;
}
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

    for (int spaces = (n - 1) / 2, stars = 1; stars <= n; spaces--, stars += 2)
        cout << string(spaces, ' ') << string(stars, '*') << "\n";
    cout << string((n - 1) / 2, ' ') << "*\n";
    cout << string((n - 3) / 2, ' ') << "***\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
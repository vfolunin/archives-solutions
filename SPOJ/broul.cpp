#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int start, bet, finish;
    cin >> start >> bet >> finish;

    if (!start && !bet && !finish)
        return 0;

    int diff = abs(start - finish);
    if (diff % bet)
        cout << "No accounting tablet\n";
    else
        cout << (diff / bet + 2) / 3 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
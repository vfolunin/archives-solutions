#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int roundCount, a, b;
    if (!(cin >> roundCount >> a >> b))
        return 0;

    a--;
    b--;
    int round = 1;
    while (a / 2 != b / 2) {
        round++;
        a /= 2;
        b /= 2;
    }

    cout << round << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
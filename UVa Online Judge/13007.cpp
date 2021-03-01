#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int playerCount, roundCount;
    if (!(cin >> playerCount >> roundCount))
        return 0;

    int res = 0;
    for (int i = 0; i < roundCount; i++) {
        int budget, daedalus;
        cin >> budget >> daedalus;

        int sum = 0;
        for (int j = 0; j < playerCount - 1; j++) {
            int x;
            cin >> x;
            sum += x;
        }

        if (sum + daedalus <= budget)
            res -= daedalus;

        for (int card : {10000, 1000, 100, 10, 1}) {
            if (sum + card <= budget) {
                res += card;
                break;
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
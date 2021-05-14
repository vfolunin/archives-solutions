#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

void solve() {
    long long roundCount, team;
    cin >> roundCount >> team;

    if (!team) {
        cout << "1 1\n";
        return;
    }

    long long best = ones(team) + 1;
    long long worst = 1LL << roundCount;
    if (team % 2 == 0) {
        int bit = 1;
        while (!(team & (1LL << bit)))
            bit++;
        worst -= (1LL << bit) - 1;
    }

    cout << best << " " << worst << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    const int N = 4e5 + 1;
    vector<long long> piles(N);

    for (int i = 1; i < N; i++) {
        piles[i] = i;
        for (int j = 1; j * j * j <= i; j++)
            piles[i] = min(piles[i], 1 + piles[i - j * j * j]);
        for (int j = 1; j * (j + 1) * (2 * j + 1) / 6 <= i; j++)
            piles[i] = min(piles[i], 1 + piles[i - j * (j + 1) * (2 * j + 1) / 6]);
    }

    return piles;
}

bool solve() {
    int n;
    cin >> n;

    if (n < 0)
        return 0;

    static vector<long long> res = prepare();

    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
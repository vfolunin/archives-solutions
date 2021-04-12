#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int stoneCount, int lastTake) {
    static vector<vector<int>> memo(1001, vector<int>(1001));
    if (memo[stoneCount][lastTake])
        return memo[stoneCount][lastTake];

    if (lastTake * 2 >= stoneCount)
        return memo[stoneCount][lastTake] = 1;

    int limit = lastTake ? lastTake * 2 : stoneCount - 1;
    for (int take = 1; take <= limit; take++)
        if (rec(stoneCount - take, take) == 2)
            return memo[stoneCount][lastTake] = 1;

    return memo[stoneCount][lastTake] = 2;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << (rec(n, 0) == 1 ? "Alicia\n" : "Roberto\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
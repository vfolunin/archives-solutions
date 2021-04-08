#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int combCount;
    cin >> combCount;

    if (!combCount)
        return 0;

    vector<int> comb, cost(512, -1);
    for (int i = 0; i < combCount; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        comb.push_back((1 << a) | (1 << b) | (1 << c));
        cin >> cost[comb.back()];
    }

    int res = -1;
    for (int i = 0; i < combCount; i++) {
        for (int j = i + 1; j < combCount; j++) {
            if (comb[i] & comb[j])
                continue;
            if (cost[511 ^ comb[i] ^ comb[j]] == -1)
                continue;
            res = max(res, cost[comb[i]] + cost[comb[j]] + cost[511 ^ comb[i] ^ comb[j]]);
        }
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
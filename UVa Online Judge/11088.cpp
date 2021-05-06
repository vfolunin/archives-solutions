#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int mask, vector<int> &cost, vector<int> &memo) {
    if (memo[mask] != -1)
        return memo[mask];
    memo[mask] = 0;
    for (int a = 0; a < cost.size(); a++)
        if (mask & (1 << a))
            for (int b = a + 1; b < cost.size(); b++)
                if (mask & (1 << b))
                    for (int c = b + 1; c < cost.size(); c++)
                        if (mask & (1 << c) && cost[a] + cost[b] + cost[c] >= 20)
                            memo[mask] = max(memo[mask], 1 + rec(mask ^ (1 << a) ^ (1 << b) ^ (1 << c), cost, memo));
    return memo[mask];
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> cost(n);
    for (int &x : cost)
        cin >> x;

    vector<int> memo(1 << n, -1);

    cout << "Case " << test << ": " << rec((1 << n) - 1, cost, memo) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
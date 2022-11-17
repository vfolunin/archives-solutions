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

    int n;
    cin >> n;

    vector<int> cost(n + 1, 1e9);
    cost[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j * j <= i; j++)
            cost[i] = min(cost[i], cost[i - j * j * j] + 1);

    cout << cost[n];
}
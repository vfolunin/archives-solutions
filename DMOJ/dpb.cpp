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

    int size, maxJump;
    cin >> size >> maxJump;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> cost(size, 1e9);
    cost[0] = 0;

    for (int i = 1; i < cost.size(); i++) {
        cost[i] = cost[i - 1] + abs(a[i - 1] - a[i]);
        for (int j = 2; j <= maxJump && j <= i; j++)
            cost[i] = min(cost[i], cost[i - j] + abs(a[i - j] - a[i]));
    }

    cout << cost.back();
}
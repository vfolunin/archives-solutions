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
 
    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    vector<long long> cost(size, 1e18);
    cost[0] = 0;

    for (int i = 1; i < cost.size(); i++) {
        cost[i] = cost[i - 1] + (a[i - 1] - a[i]) * (a[i - 1] - a[i]);
        if (i >= 2)
            cost[i] = min(cost[i], cost[i - 2] + (a[i - 2] - a[i]) * (a[i - 2] - a[i]) * 3);
        if (i + 1 < cost.size())
            cost[i] = min(cost[i], cost[i - 1] + (a[i - 1] - a[i + 1]) * (a[i - 1] - a[i + 1]) * 3 + (a[i] - a[i + 1]) * (a[i] - a[i + 1]));
    }

    cout << cost.back();
}
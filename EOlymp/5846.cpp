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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> cost(size, 1e9);
    cost[0] = 0;

    for (int i = 1; i < cost.size(); i++) {
        cost[i] = cost[i - 1] + abs(a[i - 1] - a[i]);
        if (i >= 2)
            cost[i] = min(cost[i], cost[i - 2] + abs(a[i - 2] - a[i]) * 3);
    }

    cout << cost.back();
}
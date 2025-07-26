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

    vector<vector<int>> cost(a.size(), vector<int>(2));
    cost[0][1] = a[0];

    for (int i = 1; i < a.size(); i++) {
        cost[i][0] = cost[i - 1][1];
        cost[i][1] = min(cost[i - 1][0], cost[i - 1][1]) + a[i];
    }

    cout << min(cost.back()[0], cost.back()[1]);
}
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

    vector<int> cost(size + 1, 1e9);
    cost[1] = 0;

    for (int i = 2; i < cost.size(); i++)
        for (int j : { 8, 12 })
            if (i >= j)
                cost[i] = min(cost[i], cost[i - j + 1] + 1);
    
    cout << (cost[size] != 1e9 ? cost[size] : -1);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> price(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> price[y][x];

    vector<int> order;
    iota(order.begin(), order.end(), 0);

    int res = 1e9;
    do {
        int cur = 0;
        for (int i = 0; i < order.size(); i++)
            cur += price[i][order[i]];
        res = min(res, cur);
    } while (next_permutation(order.begin(), order.end()));

    cout << res;
}
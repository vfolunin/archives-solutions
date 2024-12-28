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

    vector<int> price(size);
    for (int &price : price)
        cin >> price;

    vector<vector<int>> res(size, vector<int>(2));
    res[0] = { 0, -price[0] };
    for (int i = 1; i < size; i++) {
        res[i][0] = max(res[i - 1][0], res[i - 1][1] + price[i]);
        res[i][1] = max(res[i - 1][0] - price[i], res[i - 1][1]);
    }

    cout << max({ res.back()[0], res.back()[1], 0 });
}
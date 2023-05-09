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

    vector<vector<long long>> res(max(2, size + 1), vector<long long>(3));
    res[1] = { 1, 1, 1 };

    for (int i = 2; i < res.size(); i++) {
        res[i][0] = res[i - 1][0] + res[i - 1][1] + res[i - 1][2];
        res[i][1] = res[i - 1][0] + res[i - 1][2];
        res[i][2] = res[i - 1][0] + res[i - 1][1];
    }

    cout << res[size][0] + res[size][1] + res[size][2];
}
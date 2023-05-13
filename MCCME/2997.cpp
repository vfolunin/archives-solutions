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

    int size, width;
    cin >> size >> width;

    vector<vector<long long>> res(max(2, size + 1), vector<long long>(2));
    res[0] = res[1] = { 1, 1 };

    for (int i = 2; i < res.size(); i++) {
        for (int j = 1; j < width && j <= i; j++) {
            res[i][0] += res[i - j][1];
            res[i][1] += res[i - j][0];
        }
    }

    cout << res[size][0] + res[size][1];
}
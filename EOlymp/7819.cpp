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

    vector<vector<int>> res(a.size(), vector<int>(2));
    res[0][1] = a[0];

    for (int i = 1; i < a.size(); i++) {
        res[i][0] = max(res[i - 1][0], res[i - 1][1]);
        res[i][1] = res[i - 1][0] + a[i];
    }

    cout << max(res.back()[0], res.back()[1]);
}
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

    int h;
    cin >> h;

    vector<vector<int>> a(h);
    int maxValue = 0;

    for (vector<int> &row : a) {
        int w;
        cin >> w;

        row.resize(w);
        for (int &value : row)
            cin >> value;

        sort(row.rbegin(), row.rend());
        maxValue = max(maxValue, row[0]);
    }

    long long res = 0;
    for (vector<int> &row : a)
        res += 1LL * (maxValue - row[0]) * row.size();

    cout << res;
}
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

    vector<vector<pair<int, int>>> res(a.size(), vector<pair<int, int>>(a.size()));
    for (int i = 0; i < a.size(); i++)
        res[i][i] = { a[i], a[i] };
    for (int len = 2; len <= a.size(); len++)
        for (int l = 0, r = len - 1; r < a.size(); l++, r++)
            res[l][r] = { max(res[l + 1][r].second, res[l][r - 1].second), min(res[l + 1][r].first, res[l][r - 1].first) };

    cout << res[0][a.size() - 1].first;
}
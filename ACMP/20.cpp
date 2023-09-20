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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<vector<int>> maxSize(a.size(), vector<int>(2, 1));
    int res = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] < a[i])
            maxSize[i][0] = maxSize[i - 1][1] + 1;
        if (a[i - 1] > a[i])
            maxSize[i][1] = maxSize[i - 1][0] + 1;
        res = max({ res, maxSize[i][0], maxSize[i][1] });
    }

    cout << res;
}
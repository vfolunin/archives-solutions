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

    vector<vector<int>> a(size, vector<int>(3));
    for (vector<int> &a : a)
        for (int &value : a)
            cin >> value;

    int res = 1;
    for (int i = 0; i + 1 < a.size(); i++)
        res += a[i + 1][0] - a[i][0] > a[i][1] * a[i][2];

    cout << res;
}
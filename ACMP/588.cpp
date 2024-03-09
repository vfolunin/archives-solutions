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

    int n;
    cin >> n;

    vector<vector<int>> res = {
        {}, { -1 }, { -1 }, { -1 }, { 2, 1, 0, 1 }, { 1, 2, 0, 0, 2 }, { -1 }
    };

    if (n >= res.size()) {
        res.push_back(vector<int>(n));
        res.back()[0] = 2;
        res.back()[1] = 1;
        res.back()[n - 5] = 1;
        res.back()[n - 1] = n - 4;
        n = res.size() - 1;
    }

    for (int value : res[n])
        cout << value << "\n";
}
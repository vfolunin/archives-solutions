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

    vector<vector<int>> ways(n + 1, vector<int>(10));
    for (int last = 0; last < 10; last++)
        ways[1][last] = (last != 0 && last != 8);

    vector<vector<int>> from = {
        { 4, 6 }, { 6, 8 }, { 7, 9 }, { 4, 8 }, { 0, 3, 9 }, {}, { 0, 1, 7 }, { 2, 6 }, { 1, 3 }, { 2, 4 }
    };

    for (int size = 2; size <= n; size++)
        for (int last = 0; last < 10; last++)
            for (int prev : from[last])
                ways[size][last] += ways[size - 1][prev];

    int res = 0;
    for (int last = 0; last < 10; last++)
        res += ways[n][last];

    cout << res;
}
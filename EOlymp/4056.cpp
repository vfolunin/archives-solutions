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

    vector<vector<long long>> ways(30, vector<long long>(10));
    for (int last = 1; last < 10; last++)
        ways[1][last] = 1;

    for (int size = 2; size < 30; size++) {
        for (int last = 0; last < 10; last++) {
            ways[size][last] = ways[size - 1][last];
            if (last != 0)
                ways[size][last] += ways[size - 1][last - 1];
            if (last != 9)
                ways[size][last] += ways[size - 1][last + 1];
        }
    }

    int size;
    cin >> size;

    long long res = 0;
    for (int last = 0; last < 10; last++)
        res += ways[size][last];

    cout << res;
}
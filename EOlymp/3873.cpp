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

    int targetSize;
    cin >> targetSize;

    vector<vector<long long>> ways(targetSize + 1, vector<long long>(10));
    for (int last = 0; last < 10; last++)
        ways[1][last] = 1;

    for (int size = 2; size <= targetSize; size++)
        for (int last = 0; last < 10; last++)
            for (int prev = 0; prev <= last; prev++)
                ways[size][last] += ways[size - 1][prev];

    long long res = 0;
    for (int last = 0; last < 10; last++)
        res += ways[targetSize][last];

    cout << res;
}
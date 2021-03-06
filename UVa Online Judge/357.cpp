#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> nominals = { 1, 5, 10, 25, 50 };
    vector<vector<long long>> ways(30010, vector<long long>(nominals.size()));
    fill(ways[0].begin(), ways[0].end(), 1);

    for (int sum = 1; sum < ways.size(); sum++) {
        for (int last = 0; last < nominals.size(); last++) {
            if (last)
                ways[sum][last] = ways[sum][last - 1];
            if (nominals[last] <= sum)
                ways[sum][last] += ways[sum - nominals[last]][last];
        }
    }

    int sum;
    while (cin >> sum) {
        if (ways[sum].back() == 1)
            cout << "There is only 1 way to produce " << sum << " cents change.\n";
        else
            cout << "There are " << ways[sum].back() << " ways to produce " << sum << " cents change.\n";
    }
}
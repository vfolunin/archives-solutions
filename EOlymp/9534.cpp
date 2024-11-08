#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<long long>> ways(size, vector<long long>(2));
    ways[0][1] = 1;

    for (int i = 1; i < ways.size(); i++) {
        ways[i][0] = ways[i - 1][1];
        if (i > 1)
            ways[i][0] += ways[i - 2][1];
        ways[i][1] = ways[i - 1][0] + ways[i - 1][1];
    }

    cout << ways.back()[1];
}
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

    int targetLast, targetRows;
    cin >> targetLast >> targetRows;

    vector<vector<long long>> ways(targetRows + 1, vector<long long>(targetLast + 1));
    ways[1].assign(targetLast + 1, 1);

    for (int rows = 2; rows <= targetRows; rows++)
        for (int last = 2; last <= targetLast; last++)
            for (int prev = 1; prev + 2 <= last; prev++)
                ways[rows][last] += ways[rows - 1][prev] * (last - 1 - prev);

    cout << ways[targetRows][targetLast];
}
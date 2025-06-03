#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetSize;
    cin >> targetSize;

    vector<vector<unsigned long long>> ways(targetSize + 1, vector<unsigned long long>(3));
    ways[1] = { 1, 1, 1 };

    for (int size = 2; size <= targetSize; size++)
        for (int last = 0; last <= 2; last++)
            for (int prev = 0; prev <= 2; prev++)
                if (abs(last - prev) != 2)
                    ways[size][last] += ways[size - 1][prev];

    cout << ways.back()[0] + ways.back()[1] + ways.back()[2] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
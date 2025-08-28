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

    const long long MOD = 1e9 + 7;
    vector<vector<long long>> ways(targetSize + 1, vector<long long>(2));
    ways[0] = { 1, 1 };

    for (int size = 1; size <= targetSize; size++)
        for (int part = 1; part <= size; part++)
            ways[size][part % 2] = (ways[size][part % 2] + ways[size - part][1 - part % 2]) % MOD;
    
    cout << (ways[targetSize][0] + ways[targetSize][1]) % MOD;
}
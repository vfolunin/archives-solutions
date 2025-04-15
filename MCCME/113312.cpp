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
    for (int from = 0; from < 10; from++)
        ways[1][from] = 1;

    for (int size = 2; size < ways.size(); size++)
        for (int from = 0; from < 10; from++)
            for (int next = from; next < 10; next++)
                ways[size][from] += ways[size - 1][next];

    long long res = 0;
    for (int from = 0; from < 10; from++)
        res += ways[targetSize][from];

    cout << res;
}
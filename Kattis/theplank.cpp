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

    vector<long long> ways(n + 1);
    ways[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i && j <= 3; j++)
            ways[i] += ways[i - j];

    cout << ways[n];
}
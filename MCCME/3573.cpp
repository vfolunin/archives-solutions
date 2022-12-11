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

    for (int i = 2; i <= n; i++) {
        ways[i] += ways[i - 2];
        if (i >= 3)
            ways[i] += ways[i - 3];
    }

    cout << ways[n];
}
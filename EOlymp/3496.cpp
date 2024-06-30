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

    int sumLimit = n * (n + 1) / 2;
    if (sumLimit % 2) {
        cout << 0;
        return 0;
    }

    vector<long long> ways(sumLimit / 2 + 1);
    ways[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int sum = sumLimit / 2; sum >= i; sum--)
            ways[sum] += ways[sum - i];

    cout << ways[sumLimit / 2] / 2;
}
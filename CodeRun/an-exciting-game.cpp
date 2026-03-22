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

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> res(n + 1, 1LL << 60);
    res[0] = res[1] = 0;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            res[i] = min(res[i], max(a + res[j], b + res[i - j]));

    cout << res[n];
}
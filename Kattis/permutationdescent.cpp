#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> prepare() {
    vector<vector<long long>> ways(101, vector<long long>(100));
    const int MOD = 1001113;

    for (int size = 1; size < ways.size(); size++) {
        ways[size][0] = 1;
        for (int descents = 1; descents < size; descents++)
            ways[size][descents] = (ways[size - 1][descents] * (descents + 1) + ways[size - 1][descents - 1] * (size - descents)) % MOD;
    }

    return ways;
}

void solve() {
    int test, size, descentCount;
    cin >> test >> size >> descentCount;

    static vector<vector<long long>> ways = prepare();

    cout << test << " " << ways[size][descentCount] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    const int N = 10000, L = 22;
    vector<vector<long long>> ways(N, vector<long long>(L));
    ways[0][1] = 1;

    for (int sum = 0; sum < N; sum++) {
        for (int last = 1; last < L; last++) {
            for (int nextLast = last; nextLast < L; nextLast++) {
                int nextSum = sum + nextLast * nextLast * nextLast;
                if (nextSum >= N)
                    break;
                ways[nextSum][nextLast] += ways[sum][last];
            }
        }
    }

    vector<long long> res(N);
    for (int sum = 1; sum < N; sum++)
        for (int last = 1; last < L; last++)
            res[sum] += ways[sum][last];
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> res = prepare();
    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
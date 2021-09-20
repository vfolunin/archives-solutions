#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long rec(vector<int> &jars, int jarCount, int maxMarbles, vector<vector<long long>> &memo) {
    long long &res = memo[jarCount][maxMarbles];
    if (res != -1)
        return res;

    if (jarCount == 1)
        return res = jars[0] >= maxMarbles;
    if (maxMarbles < jarCount)
        return res = 0;

    res = rec(jars, jarCount - 1, maxMarbles, memo) * (maxMarbles - (jarCount - 1)) % MOD;

    if (jars[jarCount - 1] >= maxMarbles)
        for (int prevMaxMarbles = 1; prevMaxMarbles < maxMarbles; prevMaxMarbles++)
            res = (res + rec(jars, jarCount - 1, prevMaxMarbles, memo)) % MOD;

    return res;
}

void solve(int test) {
    int jarCount;
    cin >> jarCount;

    vector<int> jars(jarCount);
    for (int &jar : jars)
        cin >> jar;
    sort(jars.begin(), jars.end());

    vector<vector<long long>> memo(101, vector<long long>(101, -1));
    long long res = 0;
    for (int maxMarbles = jarCount; maxMarbles <= 100; maxMarbles++)
        res = (res + rec(jars, jarCount, maxMarbles, memo)) % MOD;

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
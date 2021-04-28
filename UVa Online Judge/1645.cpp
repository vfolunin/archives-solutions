#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> prepare() {
    vector<long long> res = { 1, 1 };
    for (int i = 2; i <= 1000; i++) {
        res.push_back(1);
        for (int j = 2; j < i; j++)
            if (i % j == 1)
                res.back() = (res.back() + res[j]) % MOD;
    }
    return res;
}

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> res = prepare();

    cout << "Case " << test << ": " << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
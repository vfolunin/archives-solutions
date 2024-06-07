#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

vector<long long> prepare() {
    vector<long long> factorial(1e5 + 1);
    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i % MOD;
    return factorial;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    vector<long long> factorial = prepare();

    if (abs(a - b) <= 1)
        cout << factorial[a] * factorial[b] * (a == b ? 2 : 1) % MOD;
    else
        cout << 0;
}
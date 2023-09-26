#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

long long f(long long n) {
    static unordered_map<long long, long long> memo;
    if (memo.count(n))
        return memo[n];
    long long &res = memo[n];

    if (n <= 1)
        return res = n;
    if (n % 2)
        return res = f(n / 2) + f(n / 2 + 1);
    else
        return res = f(n / 2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << f(n);
}
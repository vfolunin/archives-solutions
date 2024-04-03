#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(long long n) {
    static map<long long, long long> memo;
    if (memo.count(n))
        return memo[n];

    return memo[n] = n ? f(n / 2) + f(n / 3) : 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << f(n);
}
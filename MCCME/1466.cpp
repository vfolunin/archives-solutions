#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sum(long long n) {
    if (n % 2)
        return (n + 1) / 2 * n;
    else
        return n / 2 * (n + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = n > 0 ? sum(n) : 1 - sum(-n);
    cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toBin(long long n) {
    string res;
    for (; n; n /= 2)
        res += n % 2 + '0';
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    for (int bit = 0; (1LL << bit) <= n; bit++)
        n |= 1LL << bit;

    cout << toBin(n);
}
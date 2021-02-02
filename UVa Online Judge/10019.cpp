#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int binOnes(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int hexOnes(long long n) {
    int res = 0;
    while (n) {
        res += binOnes(n % 10);
        n /= 10;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;

    cout << binOnes(n) << " " << hexOnes(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
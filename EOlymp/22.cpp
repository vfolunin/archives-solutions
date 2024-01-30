#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;
    
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int res = 0;
    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            res += isPrime(stoi(s));
        }
    }

    cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    string s;
    cin >> l >> r >> s;

    vector<int> isPrime(1.3e6, 1);
    int res = 0;

    for (int i = 2, pi = 1; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;

            if (l <= pi && pi <= r)
                res += to_string(i).find(s) != -1;
            pi++;
        }
    }

    cout << res;
}
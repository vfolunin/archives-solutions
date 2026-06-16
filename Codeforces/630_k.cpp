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

    long long n;
    cin >> n;

    vector<int> primes = { 2, 3, 5, 7 };
    long long res = 0;
    for (int mask = 0; mask < (1 << primes.size()); mask++) {
        int ones = 0, divisor = 1;
        for (int bit = 0; bit < primes.size(); bit++) {
            if (mask & (1 << bit)) {
                ones++;
                divisor *= primes[bit];
            }
        }
        res += n / divisor * (ones % 2 ? -1 : 1);
    }

    cout << res;
}
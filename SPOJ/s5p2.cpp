#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n)
                divisors.push_back(n / d);
        }
    }
    return divisors;
}

int getPrimeDivisorCount(int n) {
    int res = 0;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            res++;
            n /= d;
        }
    }
    res += n > 1;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    for (int d : getDivisors(n))
        res += getPrimeDivisorCount(d);

    cout << res;
}
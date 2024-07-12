#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
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

    sort(divisors.begin(), divisors.end());
    return divisors;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> divisors = getDivisors(n);
    int res = 0;
    for (int i = 0; i < divisors.size(); i++)
        for (int j = i; j < divisors.size(); j++)
            res += lcm(divisors[i], divisors[j]) == n;

    cout << n << " " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
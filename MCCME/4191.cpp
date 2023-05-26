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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    vector<int> divisors = getDivisors(n);
    int res = 0;
    for (int i = 0; i < divisors.size(); i++)
        for (int j = i + 1; j < divisors.size() && divisors[i] * divisors[j] <= n; j++)
            res += gcd(divisors[i], divisors[j]) == 1;

    cout << res;
}
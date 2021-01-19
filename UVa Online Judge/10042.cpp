#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n > 9) {
        res += n % 10;
        n /= 10;
    }
    return res + n;
}

vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        res.push_back(n);
    return res;
}

bool isSmith(int n) {
    vector<int> factors = factorize(n);
    if (factors.size() == 1)
        return 0;
    int sum = digitSum(n);
    for (int &f : factors)
        sum -= digitSum(f);
    return sum == 0;
}

void solve() {
    int n;
    cin >> n;

    do
        n++;
    while (!isSmith(n));

    cout << n << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
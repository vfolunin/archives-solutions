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

    sort(divisors.begin(), divisors.end());
    return divisors;
}

bool solve() {
    int n;
    cin >> n;

    if (n == -1)
        return 0;

    vector<int> divisors = getDivisors(n);
    divisors.pop_back();

    int divisorSum = 0;
    for (int divisor : divisors)
        divisorSum += divisor;

    if (n == divisorSum) {
        cout << n << " = " << divisors[0];
        for (int i = 1; i < divisors.size(); i++)
            cout << " + " << divisors[i];
        cout << "\n";
    } else {
        cout << n << " is NOT perfect.\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
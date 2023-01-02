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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    vector<int> divisors = getDivisors(n);
    divisors.pop_back();

    int divisorSum = 0;
    for (int divisor : divisors)
        divisorSum += divisor;

    if (divisorSum == n) {
        for (int divisor : divisors)
            cout << divisor << " ";
    } else {
        cout << 0;
    }
}
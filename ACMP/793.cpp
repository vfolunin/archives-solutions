#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

vector<int> factorize(int n) {
    vector<int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n != 1)
        factorization.push_back(n);

    return factorization;
}

bool isSmithNumber(int n) {
    vector<int> factors = factorize(n);
    if (factors.size() == 1)
        return 0;

    int sum = 0;
    for (int factor : factors)
        sum += digitSum(factor);

    return sum == digitSum(n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int value; cin >> value; )
        cout << isSmithNumber(value);
}
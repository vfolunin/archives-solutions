#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long combinations(int n, int k) {
    long long res = 1;
    for (int i = n; i > n - k; i--)
        res *= i;
    for (int i = 1; i <= k; i++)
        res /= i;
    return res;
}

long long f(int n) {
    long long res = 0;
    for (int k = 0; k <= 4; k++)
        res += combinations(n - 1, k);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << f(n) << "\n";
}
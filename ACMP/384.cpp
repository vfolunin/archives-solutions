#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    int n = gcd(a, b);

    vector<int> fib = { 0, 1 };
    for (int i = 2; i <= n; i++)
        fib.push_back((fib[i - 2] + fib[i - 1]) % (int)1e9);

    cout << fib[n];
}
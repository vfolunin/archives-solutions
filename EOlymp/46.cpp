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

    int n;
    cin >> n;

    vector<long long> fib = { 1, 1 };
    for (int i = 2; fib.back() < n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    int res = 0;
    for (int i = 0; n >= fib[i]; i++) {
        n -= fib[i];
        res++;
    }

    cout << res;
}
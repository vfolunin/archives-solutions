#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("fib.in", "r", stdin);
    freopen("fib.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> fib = { 1, 1 };
    for (int i = 2; i <= n; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    cout << fib[n];
}
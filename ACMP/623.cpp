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

    vector<int> fib = { 1, 1, 2 };
    for (int i = 3; i <= n; i++) {
        fib[0] = fib[1];
        fib[1] = fib[2];
        fib[2] = (fib[0] + fib[1]) % 10;
    }

    cout << fib[min(2, n)];
}
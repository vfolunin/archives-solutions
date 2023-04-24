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
    for (int i = 2; i <= n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    cout << fib[n] * 2;
}
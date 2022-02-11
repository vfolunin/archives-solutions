#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> fib = { 0, 1 };
    for (int i = 2; i <= 45; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<long long> fib = prepare();

    cout << fib[n - 1] << " " << fib[n];
}
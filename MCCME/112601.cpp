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

    vector<long long> fib = { 0, 1, 1 };
    int res = 2;

    for (int i = 3; fib.back() < n; i++, res++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    cout << (fib.back() == n ? res : -1);
}
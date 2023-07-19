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

    vector<long long> fib = { 0, 1 };
    for (int i = 2; fib.back() <= n; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    if (auto it = find(fib.begin(), fib.end(), n); it != fib.end())
        cout << "1\n" << it - fib.begin();
    else
        cout << 0;
}
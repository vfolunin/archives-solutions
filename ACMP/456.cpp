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

    int n, sum;
    cin >> n >> sum;

    vector<int> fib = { 0, 1 };
    for (int i = 2; i < n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    for (int a = 1; a * fib[n - 2] <= sum; a++) {
        int b = (sum - a * fib[n - 2]) / fib[n - 1];
        if (a > b && a * fib[n - 2] + b * fib[n - 1] == sum) {
            cout << a << " " << b;
            break;
        }
    }
}
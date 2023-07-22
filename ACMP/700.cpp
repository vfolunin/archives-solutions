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

    int n, amount, delta;
    cin >> n >> amount >> delta;

    long long sum = amount;
    for (int i = 1; i < n; i++) {
        amount = max(amount - delta, 0);
        sum += amount;
    }

    cout << (amount ? "YES " : "NO ") << sum;
}
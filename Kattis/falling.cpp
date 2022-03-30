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

    for (int diff = 1; diff * diff <= n; diff++) {
        if (n % diff)
            continue;

        int sum = n / diff;
        if ((sum - diff) % 2)
            continue;

        int a = (sum + diff) / 2;
        int b = sum - a;
        if (a > b)
            swap(a, b);
        if (a < 0)
            continue;

        cout << a << " " << b;
        return 0;
    }

    cout << "impossible";
}
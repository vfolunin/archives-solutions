#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;

    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n)
                divisors.push_back(n / d);
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r, count;
    cin >> l >> r >> count;

    bool found = 0;
    for (int i = l; i <= r; i++) {
        vector<int> divisors = getDivisors(i);
        if (divisors.size() == count) {
            cout << i << "\n";
            for (int divisor : divisors)
                cout << divisor << " ";
            cout << "\n";
            found = 1;
        }
    }

    if (!found)
        cout << -1;
}
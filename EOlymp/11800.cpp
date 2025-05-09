#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> factorize(int n) {
    vector<int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n != 1)
        factorization.push_back(n);

    return factorization;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a = factorize(n);

    if (a.size() < 3) {
        cout << "0 0 0";
        return 0;
    }

    if (a.front() == a.back()) {
        if (a.size() < 6)
            cout << "0 0 0";
        else
            cout << a[0] << " " << a[0] * a[0] << " " << n / (a[0] * a[0] * a[0]);
        return 0;
    }

    vector<int> res = { a.front(), a.back(), n / (a.front() * a.back()) };
    if (res[0] == res[1] || res[0] == res[2])
        cout << "0 0 0";
    else
        cout << res[0] << " " << res[1] << " " << res[2];
}
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

    vector<int> res = factorize(n);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ", " : "]");
}
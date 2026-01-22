#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n)
                divisors.push_back(n / d);
        }
    }
    return divisors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> res(size + 1, 1);
    for (int i = 2; i < res.size(); i++)
        for (int d : getDivisors(i + 1))
            res[i] += res[d - 1];

    cout << res.back();
}
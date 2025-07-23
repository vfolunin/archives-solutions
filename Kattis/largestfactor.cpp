#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimeDivisors(int n) {
    vector<int> primeDivisors;

    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            primeDivisors.push_back(d);
            while (n % d == 0)
                n /= d;
        }
    }
    if (n != 1)
        primeDivisors.push_back(n);

    return primeDivisors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << getPrimeDivisors(n).back();
}
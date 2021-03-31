#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitCount(int n) {
    int res = 1;
    while (n > 9) {
        res++;
        n /= 10;
    }
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static set<int> aPrimes = { 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991 };
    auto res = aPrimes.upper_bound(n);

    if (res != aPrimes.end() && digitCount(*res) == digitCount(n))
        cout << *res << "\n";
    else
        cout << "0\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
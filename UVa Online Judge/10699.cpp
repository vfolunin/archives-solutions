#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << n << " : ";

    int res = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res++;
            while (n % i == 0)
                n /= i;
        }
    }
    res += n > 1;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
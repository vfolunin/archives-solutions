#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    long long res = 0;
    for (long long d = 1; d * d <= n; d++)
        if (n % (d * d) == 0)
            res = 8 * (d - 1);

    cout << "Case " << test << ": ";
    if (res)
        cout << res << "\n";
    else
        cout << "Impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
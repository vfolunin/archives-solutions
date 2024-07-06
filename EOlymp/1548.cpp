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

    long long l = 3, r = 1e8;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * (m - 3) / 2 < n)
            l = m;
        else
            r = m;
    }

    cout << "Case " << test << ": " << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
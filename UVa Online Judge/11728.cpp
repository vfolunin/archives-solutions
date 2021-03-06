#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Case " << test << ": ";

    for (int i = n; i >= 1; i--) {
        int sum = 0;
        for (int d = 1; d * d <= i; d++) {
            if (i % d == 0) {
                sum += d;
                if (d * d != i)
                    sum += i / d;
            }
        }

        if (sum == n) {
            cout << i << "\n";
            return 1;
        }
    }

    cout << "-1\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long alcuin(long long n) {
    if (n % 2)
        return alcuin(n + 3);
    n *= n;
    return n / 48 + (n % 48 >= 24);
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Case " << test << ": " << alcuin(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
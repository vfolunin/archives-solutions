#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimePowers(int n) {
    vector<int> primePowers;

    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            int power = 1;
            while (n % d == 0) {
                n /= d;
                power *= d;
            }
            primePowers.push_back(power);
        }
    }
    if (n != 1)
        primePowers.push_back(n);

    return primePowers;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> primePowers = getPrimePowers(n);
    while (primePowers.size() < 2)
        primePowers.push_back(1);

    long long res = 0;
    for (int primePower : primePowers)
        res += primePower;

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int factPower(int f, int p) {
    int res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Case #" << test << ": " << factPower(n, 5) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int a, b;
    cin >> a >> b;

    int sum = 0;
    for (int i = a; i <= b; i++)
        if (i % 2)
            sum += i;

    cout << "Case " << test << ": " << sum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
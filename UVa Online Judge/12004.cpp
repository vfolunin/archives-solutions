#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long n;
    cin >> n;   
    long long res = n * (n - 1) / 2;

    cout << "Case " << test << ": ";
    if (res % 2)
        cout << res << "/2\n";
    else
        cout << res / 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
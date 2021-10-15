#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n, k;
    cin >> n >> k;

    vector<int> joseph(n + 1);
    for (int i = 2; i <= n; i++)
        joseph[i] = (joseph[i - 1] + k) % i;

    cout << "Case " << test << ": " << joseph[n] + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
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

    string s(n, '0');
    fill(s.begin(), s.begin() + k, '1');
    sort(s.begin(), s.end());

    if (test)
        cout << "\n";
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}
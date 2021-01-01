#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    nth_element(v.begin(), v.begin() + n / 2, v.end());
    cout << "Case " << test << ": " << v[n / 2] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        solve(i);
}
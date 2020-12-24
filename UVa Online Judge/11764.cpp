#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int high = 0, low = 0;
    for (int i = 1; i < n; i++) {
        high += a[i - 1] < a[i];
        low += a[i - 1] > a[i];
    }
    cout << "Case #" << test << ": " << high << " " << low << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        solve(i);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    cout << "Case " << test << ": ";
    if (a[0] + a[1] <= a[2])
        cout << "Invalid\n";
    else if (a[0] == a[2])
        cout << "Equilateral\n";
    else if (a[0] == a[1] || a[1] == a[2])
        cout << "Isosceles\n";
    else
        cout << "Scalene\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
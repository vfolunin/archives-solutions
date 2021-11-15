#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.rbegin(), a.rend());
    while (m < n && a[m] == a[m - 1])
        m++;

    cout << m << "\n";
}
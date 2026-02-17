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

    int n;
    cin >> n;

    vector<long long> a(n);
    for (long long &x : a)
        cin >> x;

    for (int i = 1; i < n; i++)
        a[i] = max(a[i], a[i] + a[i - 1]);

    cout << *max_element(a.begin(), a.end());
}
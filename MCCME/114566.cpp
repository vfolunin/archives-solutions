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

    vector<long long> a(3);
    for (long long &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    if (a[0] + 1 == a[1] && a[1] + 1 == a[2])
        cout << "0\n";
    else if (a[0] + 2 == a[1] || a[1] + 2 == a[2])
        cout << "1\n";
    else
        cout << "2\n";

    cout << max({ 0LL, a[1] - a[0] - 1, a[2] - a[1] - 1 });
}
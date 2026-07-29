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

    long long value;
    cin >> value;

    sort(a.begin(), a.end());

    if (a[0] + a[1] <= a[2])
        cout << max(a[2] - a[0] - a[1] - value, 0LL);
    else
        cout << max(a[0] + a[1] - a[2] - value, 0LL);
}
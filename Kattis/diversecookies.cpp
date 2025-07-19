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

    long long n;
    cin >> n;

    vector<long long> a(3);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout << min(a[0] + a[1] + a[2], (a[0] + a[1]) * 2 + n);
}
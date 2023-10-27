#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long d = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        d = gcd(d, a[i + 1] - a[i] - 1);

    long long res = 0;
    if (d)
        for (int i = 0; i + 1 < a.size(); i++)
            res += (a[i + 1] - a[i] - 1) / d;

    cout << res;
}
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
    long long res = 0;
    do {
        res = max(res, a[0] * a[1] + a[2]);
    } while (next_permutation(a.begin(), a.end()));

    cout << res;
}
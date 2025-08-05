#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long getSum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size, cubeCount;
    cin >> size >> cubeCount;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    a.erase(a.begin(), a.begin() + a.size() / 2);

    vector<long long> p = a;
    partial_sum(p.begin(), p.end(), p.begin());

    long long l = a[0], r = 3e9;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;

        long long count = upper_bound(a.begin(), a.end(), m) - a.begin();
        if (count * m - p[count - 1] <= cubeCount)
            l = m;
        else
            r = m;
    }

    cout << l;
}
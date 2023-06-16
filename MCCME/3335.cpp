#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long mergeSort(vector<long long> &a, vector<long long> &t, int l, int r) {
    if (l == r)
        return 0;

    int m = l + (r - l) / 2;
    long long inversionCount = 0;
    inversionCount += mergeSort(a, t, l, m);
    inversionCount += mergeSort(a, t, m + 1, r);

    for (int i = l; i <= r; i++)
        t[i] = a[i];

    int ai = l, bi = m + 1;
    for (int i = l; i <= r; i++) {
        if (bi > r || ai <= m && t[ai] <= t[bi]) {
            a[i] = t[ai++];
        } else {
            inversionCount += m - ai + 1;
            a[i] = t[bi++];
        }
    }

    return inversionCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, len;
    cin >> size >> len;

    vector<long long> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        a[i] = i + len * a[i];
    }

    vector<long long> t = a;
    cout << mergeSort(a, t, 0, size - 1);
}
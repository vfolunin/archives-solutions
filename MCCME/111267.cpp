#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool mergeSort(vector<int> &a, vector<int> &t, int l, int r) {
    if (l == r)
        return 0;

    int m = l + (r - l) / 2;
    long long inversionCount = 0;
    inversionCount ^= mergeSort(a, t, l, m);
    inversionCount ^= mergeSort(a, t, m + 1, r);

    for (int i = l; i <= r; i++)
        t[i] = a[i];

    int ai = l, bi = m + 1;
    for (int i = l; i <= r; i++) {
        if (bi > r || ai <= m && t[ai] <= t[bi]) {
            a[i] = t[ai++];
        } else {
            inversionCount ^= (m - ai + 1) % 2;
            a[i] = t[bi++];
        }
    }

    return inversionCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> t(size);
    cout << mergeSort(a, t, 0, size - 1);
}
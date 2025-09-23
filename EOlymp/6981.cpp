#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

long long mergeSort(vector<int> &a, vector<int> &t, int l, int r) {
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

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    unordered_map<string, int> pos;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        pos[s] = i;
    }

    vector<int> a(size);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        a[i] = pos[s];
    }

    vector<int> t(size);
    
    cout << mergeSort(a, t, 0, a.size() - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
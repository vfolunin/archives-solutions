#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(vector<long long> &a, int l, int r) {
    if (l > r)
        return 0;

    if (l == r) {
        a[l] = 1;
        return 1;
    }

    int m = l + (r - l) / 2;
    long long sum = rec(a, l, m - 1);
    sum += rec(a, m + 1, r);
    a[m] = sum + 1;
    sum += a[m];
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> a(size);
    rec(a, 0, size - 1);

    for (long long &value : a)
        cout << value << " ";
}
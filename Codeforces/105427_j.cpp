#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, int limit, int sumLimit) {
    if (sumLimit < a.back())
        return 0;

    int count = 0;
    for (int l = 0, r = a.size() - 1; l <= r; r--, count++)
        if (l < r && a[l] + a[r] <= sumLimit)
            l++;
    return count <= limit;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int l = 0, r = 1;
    while (!can(a, limit, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, limit, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}
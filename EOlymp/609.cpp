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

    int size, sumLimit;
    cin >> size >> sumLimit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if (a.back() > sumLimit) {
        cout << "Impossible";
        return 0;
    }

    int res = 0;
    for (int l = 0, r = a.size() - 1; l <= r; r--) {
        if (l < r && a[l] + a[r] <= sumLimit)
            l++;
        res++;
    }

    cout << res;
}
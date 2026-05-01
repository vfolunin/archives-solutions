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

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int res = a.size();
    for (int l = 0, r = 0; r < a.size(); r++) {
        while (a[r] - a[l] > limit)
            l++;
        res = min<int>(res, a.size() - (r - l + 1));
    }

    cout << res;
}
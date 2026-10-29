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

    long long res = 0;
    for (int l = 0, m = 0, r = 0; m < a.size(); m++) {
        while (a[l] + limit < a[m])
            l++;
        while (r < a.size() && a[r] < a[m] + limit)
            r++;
        res += (r - l - 1) * (a.size() - (r - l));
    }

    cout << res;
}
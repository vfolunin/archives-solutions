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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int sum = 0, res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        sum += a[r];
        while (l + 1 < r && a[l] + a[l + 1] < a[r])
            sum -= a[l++];
        res = max(res, sum);
    }

    cout << res;
}
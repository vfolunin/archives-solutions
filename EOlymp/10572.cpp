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

    vector<int> count(a.size());
    for (int l = 0, r = 0; r < a.size(); r++) {
        while (a[l] + limit < a[r])
            l++;
        count[r] = r - l + 1;
    }

    int leftCount = 0, res = 0;
    for (int l = 0, r = 0; r < a.size(); r++) {
        while (l + count[r] <= r)
            leftCount = max(leftCount, count[l++]);
        res = max(res, leftCount + count[r]);
    }

    cout << res;
}
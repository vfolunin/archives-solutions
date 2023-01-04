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

    int size, delta;
    cin >> size >> delta;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    long long res = 0;
    for (int l = 0, r = 0; l < a.size(); l++) {
        while (r < a.size() && a[r] - a[l] <= delta)
            r++;
        res += r - l - 1;
    }

    cout << res;
}
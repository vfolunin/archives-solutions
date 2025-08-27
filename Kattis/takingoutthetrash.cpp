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

    int size, maxSum;
    cin >> size >> maxSum;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    int res = 0;

    for (int l = 0, r = size - 1; l <= r; l++, r--) {
        while (l < r && a[l] + a[r] > maxSum) {
            res++;
            r--;
        }
        res++;
    }

    cout << res;
}
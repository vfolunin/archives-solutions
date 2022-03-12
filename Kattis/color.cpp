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

    int size, capacity, maxDiff;
    cin >> size >> capacity >> maxDiff;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int res = 0, curRow = 1;
    for (int i = 1; i < size; i++) {
        if (a[i] - a[i - 1] <= maxDiff) {
            curRow++;
        } else {
            res += (curRow + capacity - 1) / capacity;
            curRow = 1;
        }
    }
    res += (curRow + capacity - 1) / capacity;

    cout << res;
}
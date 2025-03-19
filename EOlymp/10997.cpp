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

    int size, targetSum;
    cin >> size >> targetSum;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int sum = 0, res = 0;
    for (int l = 0, r = 0; r < size; r++) {
        sum += a[r];
        while (sum > targetSum) {
            sum -= a[l];
            l++;
        }
        res = max(res, r - l + 1);

    }

    cout << res;
}
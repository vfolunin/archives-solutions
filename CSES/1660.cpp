#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, targetSum;
    cin >> n >> targetSum;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int segmentCount = 0;

    int curSum = 0;
    for (int l = 0, r = 0; r < n; r++) {
        curSum += a[r];

        while (curSum > targetSum) {
            curSum -= a[l];
            l++;
        }

        if (curSum == targetSum)
            segmentCount++;
    }

    cout << segmentCount;
}
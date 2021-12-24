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

    int n;
    cin >> n;

    int curSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curSum = max(curSum + x, x);
        maxSum = max(maxSum, curSum);
    }

    cout << maxSum << "\n";
}
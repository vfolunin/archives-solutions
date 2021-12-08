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

    map<int, int> count;
    int maxVal, maxCount = 0;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        count[val]++;
        if (maxCount < count[val] || maxCount == count[val] && maxVal < val) {
            maxCount = count[val];
            maxVal = val;
        }
    }

    cout << maxVal << "\n";
}
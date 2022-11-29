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

    int curSum = a[0], curL = 0, curR = 0;
    int resSum = a[0], resL = 0, resR = 0;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] >= curSum + a[i]) {
            curSum = a[i];
            curL = curR = i;
        } else {
            curSum += a[i];
            curR = i;
        }
        if (resSum < curSum) {
            resSum = curSum;
            resL = curL;
            resR = curR;
        }
    }

    cout << resL + 1 << "\n" << resR + 1;
}
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

    int res = 360;
    for (int l = 0; l < a.size(); l++) {
        int sum = 0;
        for (int r = l; r < a.size(); r++) {
            sum += a[r];
            res = min(res, abs(sum - (360 - sum)));
        }
    }

    cout << res;
}
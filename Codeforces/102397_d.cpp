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

    int size, threshold;
    cin >> size >> threshold;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int sum = 0, res = a.size() + 1;
    for (int l = 0, r = 0; l < a.size(); l++) {
        while (r < a.size() && sum < threshold) {
            sum += a[r];
            r++;
        }
        if (sum >= threshold)
            res = min(res, r - l);
        sum -= a[l];
    }

    cout << (res <= a.size() ? res : -1);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    unordered_map<int, int> count;
    int res, resCount = 0;
    for (int aValue : a) {
        for (int bValue : b) {
            if (aValue <= bValue) {
                count[bValue - aValue]++;
                if (resCount < count[bValue - aValue] || resCount == count[bValue - aValue] && res > bValue - aValue) {
                    resCount = count[bValue - aValue];
                    res = bValue - aValue;
                }
            }
        }
    }

    cout << res;
}
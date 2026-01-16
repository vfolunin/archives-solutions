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

    int l = 0, r = a.size() - 1, resL = l, resR = r;
    long long lSum = a[l], rSum = a[r], resDiff = abs(lSum - rSum);
    while (l + 1 < r) {
        if (lSum < rSum)
            lSum += a[++l];
        else
            rSum += a[--r];

        long long diff = abs(lSum - rSum);
        if (resDiff > diff) {
            resDiff = diff;
            resL = l;
            resR = r;
        }
    }

    cout << resDiff << " " << resL + 1 << " " << resR + 1;
}
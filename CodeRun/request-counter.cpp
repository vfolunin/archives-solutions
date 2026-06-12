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

    int size, width;
    cin >> size >> width;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = a.size() - 1; i; i--)
        if (a[i] >= a[i - 1])
            a[i] -= a[i - 1];

    long long cur = 0;
    for (int i = 0; i < width; i++)
        cur += a[i];
    
    long long res = cur;
    for (int i = width; i < a.size(); i++) {
        cur += a[i] - a[i - width];
        res = max(res, cur);
    }

    cout << res;
}
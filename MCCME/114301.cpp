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

    int cur = 0;
    for (int i = 1; i < width; i++)
        cur += a[i - 1] < a[i];

    int res = cur;
    for (int i = width; i < a.size(); i++) {
        cur -= a[i - width] < a[i - width + 1];
        cur += a[i - 1] < a[i];
        res = min(res, cur);
    }

    cout << res;
}
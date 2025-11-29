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

    int res = 0, cur = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] < a[i])
            cur += a[i] - a[i - 1];
        else
            cur = 0;
        res = max(res, cur);
    }

    cout << res;
}
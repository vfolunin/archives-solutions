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

    int count = 0, res = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        res = max(res, a[i] + count);
        count += a[i] > 0;
    }

    cout << res;
}
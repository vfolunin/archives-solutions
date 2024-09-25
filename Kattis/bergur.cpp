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

    int res = a.back();
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        a[i] = min(a[i], a[i + 1]);
        res += a[i];
    }

    cout << res;
}
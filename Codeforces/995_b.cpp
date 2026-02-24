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

    vector<int> a(size * 2);
    for (int &value : a)
        cin >> value;

    int res = 0;
    while (!a.empty()) {
        int value = a[0];
        a.erase(a.begin());
        auto it = find(a.begin(), a.end(), value);
        res += it - a.begin();
        a.erase(it);
    }

    cout << res;
}
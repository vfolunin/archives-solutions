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

    vector<int> res;
    for (int l = 0, r = a.size() - 1; l <= r; l++, r--) {
        res.push_back(a[l]);
        if (l < r)
            res.push_back(a[r]);
    }

    reverse(res.begin(), res.end());

    for (int value : res)
        cout << value << " ";
}
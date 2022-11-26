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

    vector<int> a(20);
    for (int &value : a)
        cin >> value;

    int res = a.size();
    for (int l = 0, r = 0; l < a.size(); l++) {
        if (a[l]) {
            while (r <= l || r < a.size() && a[r])
                r++;
            if (r < a.size())
                res = min(res, r - l - 1);
        }
    }

    cout << (res != a.size() ? res : -1);
}
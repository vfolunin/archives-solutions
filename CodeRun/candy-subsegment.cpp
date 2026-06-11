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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    unordered_map<int, int> count;
    int res = 0;

    for (int l = 0, r = 0; r < a.size(); r++) {
        count[a[r]]++;
        while (count.size() > 2) {
            if (!--count[a[l]])
                count.erase(a[l]);
            l++;
        }
        if (count.size() == 2)
            res = max(res, r - l + 1);
    }

    cout << res;
}
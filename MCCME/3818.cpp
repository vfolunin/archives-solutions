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

    vector<int> a(10);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            int cur = 1e9;
            for (int j = 0; j < a.size(); j++)
                if (a[j] == 2)
                    cur = min(cur, abs(i - j));
            res = max(res, cur);
        }
    }

    cout << res;
}
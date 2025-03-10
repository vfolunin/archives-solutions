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

    int queryCount;
    cin >> queryCount;

    int res = 0;
    for (int i = 0; i < queryCount; i++) {
        int type, delta;
        cin >> type >> delta;

        if (type)
            res -= min(res, delta);
        else
            res += delta;
    }

    cout << res;
}
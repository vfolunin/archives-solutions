#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("cubes.in", "r", stdin);
    freopen("cubes.out", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 1e9;
    for (int target = 0; target <= 1000; target++) {
        int add = 0, remove = 0;
        for (int value : a) {
            if (value < target)
                add += target - value;
            else
                remove += value - target;
        }
        res = min(res, max(add, remove));
    }

    cout << res;
}
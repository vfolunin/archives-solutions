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

    int cur = -1e9, res = -1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        cur = max(cur + value, value);
        res = max(res, cur);
    }

    cout << res;
}
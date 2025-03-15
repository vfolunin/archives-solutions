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

    int res = 2e9;
    for (int i = 0; i < size; i++) {
        int cur = 0;
        for (int j = 0; j < size; j++)
            cur += a[(i + j) % a.size()] * j;
        res = min(res, cur);
    }

    cout << res;
}
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

    int size, colorCount;
    cin >> size >> colorCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int row = 1, res = 1;
    for (int i = 1; i < size; i++) {
        if (a[i - 1] != a[i])
            row++;
        else
            row = 1;
        res = max(res, row);
    }

    cout << res;
}
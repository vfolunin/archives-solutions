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

    int size, xorValue;
    cin >> size >> xorValue;
    size = 1 << size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int i = 0; i < size; i++)
        if ((i ^ xorValue) < size)
            res = max(res, a[i] + a[i ^ xorValue]);

    cout << res;
}
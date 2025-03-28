#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> res(size);
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int lhs, int rhs) {
        return a[lhs] > a[rhs];
    });

    for (int index : res)
        cout << index + 1 << " ";
}
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

    vector<int> a(4);
    for (int &value : a)
        cin >> value;

    vector<int> index = { 0, 1, 2, 3 };
    sort(index.begin(), index.end(), [&](int lhs, int rhs) {
        return a[lhs] > a[rhs];
    });

    for (int i : index)
        cout << i + 1 << " ";
}
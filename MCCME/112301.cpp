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

    int l, r, shift;
    cin >> l >> r >> shift;
    l--;
    r--;

    rotate(a.begin() + l, a.begin() + l + shift % (r - l + 1), a.begin() + r + 1);

    for (int value : a)
        cout << value << " ";
}
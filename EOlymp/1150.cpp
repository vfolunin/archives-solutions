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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < queryCount; i++) {
        int l, r, index;
        cin >> l >> r >> index;
        l--;
        r--;
        index--;

        vector<int> part(a.begin() + l, a.begin() + r + 1);
        nth_element(part.begin(), part.begin() + index, part.end());

        cout << part[index] << "\n";
    }
}
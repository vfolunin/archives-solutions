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

    for (int l = 0, r = (a.size() + 1) / 2; l < (a.size() + 1) / 2; l++, r++) {
        cout << a[l] << " ";
        if (r < a.size())
            cout << a[r] << " ";
    }
}
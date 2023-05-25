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

    for (int l = 0, r = (int)a.size() - 1; l < r; l++, r--) {
        while (l < r && a[l] % 2)
            l++;
        while (l < r && a[r] % 2)
            r--;
        if (l < r)
            swap(a[l], a[r]);
    }

    for (int value : a)
        cout << value << " ";
}
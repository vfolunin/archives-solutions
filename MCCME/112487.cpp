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

    vector<int> a;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
    }

    for (int l = 0, r = (int)a.size() - 1; l < r; l++, r--)
        cout << a[l] + a[r] << " ";
    if (a.size() % 2)
        cout << a[a.size() / 2];
}
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

    int size, type;
    cin >> size >> type;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    if (type == 1) {

        for (int l = 0, r = size - 1; l < r; l++) {
            while (l < r && a[l] + a[r] > 7777)
                r--;
            if (l < r && a[l] + a[r] == 7777) {
                cout << "Yes";
                return 0;
            }
        }
        cout << "No";

    } else if (type == 2) {

        if (std::unique(a.begin(), a.end()) == a.end())
            cout << "Unique";
        else
            cout << "Contains duplicate";

    } else if (type == 3) {

        map<int, int> count;
        for (int x : a)
            count[x]++;
        for (auto &[x, k] : count) {
            if (k * 2 > size) {
                cout << x;
                return 0;
            }
        }
        cout << -1;

    } else if (type == 4) {

        if (size % 2)
            cout << a[size / 2];
        else
            cout << a[size / 2 - 1] << " " << a[size / 2];

    } else {

        for (int x : a)
            if (100 <= x && x <= 999)
                cout << x << " ";

    }
}
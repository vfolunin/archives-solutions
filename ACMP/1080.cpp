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

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "get") {
            int index;
            cin >> index;

            cout << a[index - 1] << "\n";
        } else if (type == "update") {
            int l, r, value;
            cin >> l >> r >> value;

            fill(a.begin() + l - 1, a.begin() + r, value);
        } else if (type == "add") {
            int l, r, value;
            cin >> l >> r >> value;

            for (int i = l - 1; i < r; i++)
                a[i] += value;
        } else if (type == "rsq") {
            int l, r;
            cin >> l >> r;

            cout << accumulate(a.begin() + l - 1, a.begin() + r, 0) << "\n";
        } else {
            int l, r;
            cin >> l >> r;

            cout << *min_element(a.begin() + l - 1, a.begin() + r) << "\n";
        }
    }
}
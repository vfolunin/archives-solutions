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
    for (int &x : a)
        cin >> x;

    vector<int> res;
    for (int i = 0; i + 2 < a.size(); i++) {
        if (a[i] < a[i + 1] && a[i + 1] < a[i + 2] ||
            a[i] > a[i + 1] && a[i + 1] > a[i + 2]) {
            swap(a[i + 1], a[i + 2]);
            res.push_back(i + 1);
        }
    }

    cout << res.size() << "\n";
    for (int index : res)
        cout << index + 1 << " ";
}
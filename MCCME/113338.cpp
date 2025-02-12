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

    vector<int> pos = { -1 };
    for (int i = 0; i + 3 <= size; i++)
        if (a[i] == a[i + 1] && a[i] == a[i + 2])
            pos.push_back(i);
    pos.push_back(a.size() - 2);

    int l = 0, r = 0;
    for (int i = 0; i + 1 < pos.size(); i++) {
        if (r - l < pos[i + 1] - pos[i]) {
            l = pos[i] + 1;
            r = pos[i + 1] + 1;
        }
    }

    cout << l + 1 << " " << r + 1;
}
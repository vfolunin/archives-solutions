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

    int size, dist;
    cin >> size >> dist;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    vector<vector<int>> groups(1);
    for (int i = 0; i < a.size(); i++) {
        if (i && a[i - 1] + dist < a[i])
            groups.emplace_back();
        groups.back().push_back(a[i]);
    }

    cout << groups.size() << "\n";
    for (vector<int> &group : groups) {
        for (int value : group)
            cout << value << " ";
        cout << "\n";
    }
}
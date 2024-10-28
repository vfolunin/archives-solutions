#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const vector<int> &a) {
    vector<int> p(a.size());
    for (int i = 1; i < a.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && a[i] != a[border])
            border = p[border - 1];
        p[i] = border + (a[i] == a[border]);
    }
    return p;
}

pair<int, vector<int>> readDiff() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> diff(max(size - 1, 0));
    for (int i = 0; i < diff.size(); i++)
        diff[i] = a[i + 1] - a[i];
    return { size, diff };
}

void solve() {
    auto [aSize, a] = readDiff();
    auto [bSize, b] = readDiff();

    if (bSize == 0) {
        cout << "0\n";
    } else if (aSize == 1) {
        cout << "1\n";
    } else {
        a.push_back(2e9);
        a.insert(a.end(), b.begin(), b.end());

        vector<int> p = prefixFunction(a);

        cout << (*max_element(p.begin(), p.end()) == aSize - 1) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
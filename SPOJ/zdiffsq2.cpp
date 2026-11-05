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

    vector<vector<int>> a(1);
    for (int value; cin >> value; )
        a.back().push_back(value);

    while (a.back().size() > 1) {
        a.emplace_back();
        for (int i = 0; i + 1 < a[a.size() - 2].size(); i++)
            a.back().push_back(a[a.size() - 2][i + 1] - a[a.size() - 2][i]);
    }

    for (int i = 0; i < 3; i++) {
        a.back().push_back(a.back().back());
        for (int j = (int)a.size() - 2; j >= 0; j--)
            a[j].push_back(a[j].back() + a[j + 1].back());

        cout << a[0].back() << " ";
    }
}
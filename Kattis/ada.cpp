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

    vector<vector<int>> a(1, vector<int>(size));
    for (int &value : a[0])
        cin >> value;

    while (*min_element(a.back().begin(), a.back().end()) != *max_element(a.back().begin(), a.back().end())) {
        a.emplace_back();
        for (int i = 1; i < a[a.size() - 2].size(); i++)
            a.back().push_back(a[a.size() - 2][i] - a[a.size() - 2][i - 1]);
    }

    a.back().push_back(a.back().back());
    for (int i = a.size() - 2; i >= 0; i--)
        a[i].push_back(a[i].back() + a[i + 1].back());

    cout << a.size() - 1 << " " << a[0].back();
}
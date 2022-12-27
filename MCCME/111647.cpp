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
 
    vector<pair<int, string>> pairs;
    int a;
    string b;
    while (cin >> a >> b)
        pairs.push_back({ a, b });

    stable_sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.first < b.first;
        });

    for (auto &[a, b] : pairs)
        cout << a << " " << b << "\n";
}
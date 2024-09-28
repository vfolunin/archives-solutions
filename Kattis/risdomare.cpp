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
    string type;
    cin >> size >> type;

    vector<pair<int, int>> pairs(size);
    for (auto &[a, b] : pairs)
        cin >> a >> b;

    cout << max_element(pairs.begin(), pairs.end(), [&](auto &a, auto &b) {
        if (a.first + a.second != b.first + b.second)
            return a.first + a.second < b.first + b.second;
        else if (type == "antal")
            return a.first < b.first;
        else
            return a.second < b.second;
    }) - pairs.begin() + 1;
}
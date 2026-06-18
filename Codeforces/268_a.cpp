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

    vector<pair<int, int>> color(size);
    vector<int> count(101);
    for (auto &[a, b] : color) {
        cin >> a >> b;
        count[b]++;
    }

    int res = 0;
    for (auto &[a, b] : color)
        res += count[a];

    cout << res;
}
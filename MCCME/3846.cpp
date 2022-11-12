#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<int, int> count;
    int value;
    while (cin >> value)
        count[value]++;

    int res = 0;
    for (auto &[value, count] : count)
        res += count * (count - 1) / 2;

    cout << res;
}
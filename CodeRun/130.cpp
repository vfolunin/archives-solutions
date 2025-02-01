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

    map<char, int> count;
    int maxCount = 0;
    for (char c; cin >> c; c++)
        maxCount = max(maxCount, ++count[c]);

    for (int y = maxCount; y; y--) {
        for (auto &[c, count] : count)
            cout << (count >= y ? "#" : " ");
        cout << "\n";
    }
    for (auto &[c, count] : count)
        cout << c;
}
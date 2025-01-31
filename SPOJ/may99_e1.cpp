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

    string s;
    cin >> s;

    map<char, int> count;
    int maxCount = 0;
    for (char c : s)
        maxCount = max(maxCount, ++count[c]);

    for (auto &[c, count] : count) {
        if (count == maxCount) {
            cout << c;
            break;
        }
    }
}
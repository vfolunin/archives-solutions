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

    string s;
    cin >> s;

    unordered_map<char, int> count;
    int maxCount = 0;
    for (char c : s)
        maxCount = max(maxCount, ++count[c]);

    cout << maxCount << "\n";

    for (char c : s) {
        if (count[c] == maxCount) {
            cout << c << " ";
            count.erase(c);
        }
    }
}
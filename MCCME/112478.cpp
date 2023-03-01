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
    for (char c : s)
        count[c]++;

    bool found = 0;
    for (auto [c, count] : count) {
        if (count == 1) {
            cout << c;
            found = 1;
        }
    }

    if (!found)
        cout << "NO";
}
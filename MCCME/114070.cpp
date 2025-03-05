#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_set<string> substrings;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
            substrings.insert(s.substr(l, r - l + 1));

    cout << substrings.size();
}
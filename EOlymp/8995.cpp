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
    for (char c : s)
        count[c]++;

    bool found = 0;
    for (char c : s) {
        if (count[c] > 1) {
            cout << c;
            found = 1;
            count[c] = 1;
        }
    }

    if (!found)
        cout << "NO";
}
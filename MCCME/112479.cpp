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

    vector<int> seen(10);
    for (char c : s)
        if (isdigit(c))
            seen[c - '0'] = 1;

    bool found = 0;
    for (int i = seen.size() - 1; i >= 0; i--) {
        if (!seen[i]) {
            cout << i;
            found = 1;
        }
    }

    if (!found)
        cout << "NO";
}
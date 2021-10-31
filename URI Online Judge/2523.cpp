#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    int n;
    if (!(cin >> s >> n))
        return 0;

    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        cout << s[index - 1];
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
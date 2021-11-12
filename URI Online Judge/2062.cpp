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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.size() == 3 && s[0] == 'U' && s[1] == 'R')
            s = "URI";
        else if (s.size() == 3 && s[0] == 'O' && s[1] == 'B')
            s = "OBI";

        cout << s << (i + 1 < n ? " " : "\n");
    }
}
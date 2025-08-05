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

    for (int len = 1; len < s.size(); len++) {
        if (s.size() % len)
            continue;

        string startPart = s.substr(0, len);
        sort(startPart.begin(), startPart.end());

        int ok = 1;
        for (int i = len; i < s.size() && ok; i += len) {
            string part = s.substr(i, len);
            sort(part.begin(), part.end());
            ok &= startPart == part;
        }

        if (ok) {
            cout << s.substr(0, len);
            return 0;
        }
    }

    cout << -1;
}
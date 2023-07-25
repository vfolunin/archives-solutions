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

    if (!isupper(s[0])) {
        cout << "No";
        return 0;
    }

    int last = 0;
    for (int i = 1; i < s.size(); i++) {
        if (isupper(s[i])) {
            if (i - last < 2 || i - last > 4) {
                cout << "No";
                return 0;
            }
            last = i;
        }
    }

    cout << (2 <= s.size() - last && s.size() - last <= 4 ? "Yes" : "No");
}
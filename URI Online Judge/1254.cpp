#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b, text;
    if (!(cin >> a >> b))
        return 0;
    cin.ignore();
    getline(cin, text);

    int depth = 0;
    string match, res;

    for (char c : text) {
        if (depth && tolower(c) == tolower(a[match.size()])) {
            match += c;
            if (match.size() == a.size()) {
                res += b;
                match.clear();
            }
        } else {
            res += match;
            match.clear();
            if (c == '<')
                depth++;
            else if (c == '>')
                depth--;
            res += c;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
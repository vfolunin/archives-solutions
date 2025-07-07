#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    static vector<string> codes = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            res += 7;
        } else {
            string &code = codes[s[i] - 'a'];
            for (int j = 0; j < code.size(); j++) {
                res += code[j] == '.' ? 1 : 3;
                res += j + 1 < code.size();
            }
            if (i + 1 < s.size() && s[i + 1] != ' ')
                res += 3;
        }
    }

    cout << s << ": length = " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}
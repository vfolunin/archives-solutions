#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

int kmp(string &text, string &word) {
    vector<int> p = prefixFunction(word + " " + text);
    int i = find(p.begin(), p.end(), word.size()) - p.begin();
    return i != p.size() ? i - 2 * word.size() : -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> a >> b;

    a += a;
    for (int i = 0; i <= 26; i++) {
        if (int j = kmp(a, b); j != -1) {
            cout << "Success\n" << (b.size() - j) % b.size() << " " << i;
            return 0;
        }

        for (char &c : b)
            c = (c - 'a' + 25) % 26 + 'a';
    }

    cout << "Impossible";
}
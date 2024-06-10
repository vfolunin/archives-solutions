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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    if (a.size() < b.size())
        a.swap(b);

    if (a.find(b) != -1) {
        cout << a;
        return 0;
    }

    int abSize = prefixFunction(b + "#" + a).back();
    string res = a + b.substr(abSize);

    int baSize = prefixFunction(a + "#" + b).back();
    if (abSize < baSize)
        res = b + a.substr(baSize);

    cout << res;
}
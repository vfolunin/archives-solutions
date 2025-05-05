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

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    string s;
    cin >> s;

    vector<int> p = prefixFunction(s);

    cout << "Test case #" << test << "\n";
    for (int i = 1; i < n; i++) {
        int period = i + 1 - p[i];
        if ((i + 1) % period == 0 && i + 1 > period)
            cout << i + 1 << " " << (i + 1) / period << "\n";
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
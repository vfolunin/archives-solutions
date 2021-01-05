#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border && s[border] != s[i])
            border = p[border - 1];
        p[i] = border + (s[border] == s[i]);
    }

    int period = s.size() - p.back();
    if (s.size() % period)
        period = s.size();

    if (test)
        cout << "\n";
    cout << period << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}
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
    int n;
    cin >> s >> n;

    if (n > 0) {
        for (int i = 0; i < s.size() * n && i < 1023; i++)
            cout << s[i % s.size()];
    } else {
        bool ok = s.size() % -n == 0;
        
        int len = s.size() / -n;
        for (int i = len; ok && i < s.size(); i++)
            ok &= s[i] == s[i - len];

        cout << (ok ? s.substr(0, len) : "NO SOLUTION");
    }
}
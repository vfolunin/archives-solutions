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

    string symbols = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < s.size(); i++) {
        int code = symbols.find(s[i]);
        code -= s.size() + i;
        code = (code % (int)symbols.size() + symbols.size()) % symbols.size();
        s[i] = symbols[code];
    }

    cout << s;
}
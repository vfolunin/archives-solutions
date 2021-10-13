#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    char c;
    string s;
    cin >> c >> s;

    if (c == '0' && s == "0")
        return 0;

    s.erase(remove(s.begin(), s.end(), c), s.end());

    int leadingZeros = 0;
    while (leadingZeros < s.size() && s[leadingZeros] == '0')
        leadingZeros++;
    s = s.substr(leadingZeros);

    if (s.empty())
        s = "0";

    cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}
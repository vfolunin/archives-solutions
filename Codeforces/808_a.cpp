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

    if (s[0] == '9')
        cout << stoll("1" + string(s.size(), '0')) - stoll(s);
    else
        cout << stoll(string(1, s[0] + 1) + string(s.size() - 1, '0')) - stoll(s);
}
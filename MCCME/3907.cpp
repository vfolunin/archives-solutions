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

    int a = 0, b = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        a += s[i] == '*' && s[i - 1] != '*' && s[i + 1] != '*' || isdigit(s[i]) && isalpha(s[i + 1]);
        b += s[i] == '*' && s[i + 1] == '*';
    }

    cout << a << " " << b;
}
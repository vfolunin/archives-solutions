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

    cout << s[2] << s[6] << s[10] << "\n";
    cout << s[0] << s.substr(s.size() - 2) << "\n";
    cout << s.substr(0, 7) << "\n";
    cout << s.substr(4) << "\n";

    for (int i = 1; i < s.size(); i += 2)
        cout << s[i];
    cout << "\n";

    cout << s.size() / 2 << "\n";

    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
}
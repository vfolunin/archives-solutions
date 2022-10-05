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

    cout << s[2] << "\n";
    cout << s[s.size() - 2] << "\n";
    cout << s.substr(0, 5) << "\n";
    cout << s.substr(0, s.size() - 2) << "\n";

    for (int i = 0; i < s.size(); i += 2)
        cout << s[i];
    cout << "\n";

    for (int i = 1; i < s.size(); i += 2)
        cout << s[i];
    cout << "\n";

    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
    cout << "\n";

    for (int i = s.size() - 1; i >= 0; i -= 2)
        cout << s[i];
    cout << "\n";

    cout << s.size();
}
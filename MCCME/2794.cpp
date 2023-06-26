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
    getline(cin, s);

    cout << s.substr(0, min<int>(s.size(), 5)) << "\n";
    cout << s.substr(0, s.size() - 1) << "\n";
    cout << s.substr(0, min<int>(s.size(), 5)) << s.substr(s.size() - min<int>(s.size(), 5)) << "\n";
    cout << string(s.rbegin(), s.rend()) << "\n";

    for (int i = 0; i < s.size(); i += 2)
        cout << s[i];
    cout << "\n";

    for (int i = 1; i < s.size(); i += 2)
        cout << s[i];
    cout << "\n";

    for (int i = 0; i < s.size(); i++)
        cout << s[i] << (i + 1 < s.size() ? " " : "\n");

    cout << (int)s.find(' ') << "\n";
    cout << count(s.begin(), s.end(), ' ') << "\n";
    cout << s.size() << "\n";
    cout << (int)s.find('a', s.size() / 2) << "\n";
    cout << count(s.begin(), s.end(), 'f') + count(s.begin(), s.end(), 'F') << "\n";

    for (int i = 0; i < s.size(); i++)
        cout << s[i] << (i + 1 < s.size() ? "," : ".\n");

    cout << "\"That's all!\"";
}
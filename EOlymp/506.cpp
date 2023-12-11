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

    for (string s; getline(cin, s); ) {
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && s.substr(i, 2) == "//") {
                cout << s.substr(i);
                break;
            } else if (i + 1 < s.size() && s.substr(i, 2) == "->") {
                cout << ".";
                i++;
            } else {
                cout << s[i];
            }
        }
        cout << "\n";
    }
}
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

    string vowels = "aeiou";
    for (int i = s.size() - 1; 1; i--) {
        if (vowels.find(tolower(s[i])) != -1) {
            cout << s.substr(0, i + 1) + "ntry";
            break;
        }
    }
}
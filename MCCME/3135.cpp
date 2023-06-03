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
    char c;
    cin >> s >> c;

    const string VOWELS = "aeiou";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (VOWELS.find(s[i]) != -1)
            cout << c << s[i];
    }
}
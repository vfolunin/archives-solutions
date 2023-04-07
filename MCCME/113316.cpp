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

    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))
            s[i] = i && isalpha(s[i - 1]) ? tolower(s[i]) : toupper(s[i]);

    cout << s;
}
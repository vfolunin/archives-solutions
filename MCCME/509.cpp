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

    for (int i = 1; i + 1 < s.size(); i++)
        if (isalpha(s[i - 1]) && s[i] == '-' && isalpha(s[i + 1]))
            s[i] = '#';

    for (char &c : s)
        if (c == '#')
            c = 'a';

    int wordCount = 0;
    for (int i = 0; i < s.size(); i++)
        wordCount += isalpha(s[i]) && (!i || !isalpha(s[i - 1]));

    cout << wordCount;
}
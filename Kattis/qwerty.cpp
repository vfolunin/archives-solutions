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
    getline(cin, s);

    string letters = "qwertyuiopasdfghjklzxcvbnm";
    for (char &c : s)
        if (isalpha(c))
            c = letters[c - 'a'];

    cout << s;
}
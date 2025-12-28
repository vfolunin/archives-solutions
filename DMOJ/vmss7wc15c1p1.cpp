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

    if (s[0] + s[1] + s[2] == s[4] + s[5] + s[6] && s[0] + s[1] + s[2] == s[8] + s[9] + s[10] + s[11] - '0')
        cout << "Goony!";
    else
        cout << "Pick up the phone!";
}
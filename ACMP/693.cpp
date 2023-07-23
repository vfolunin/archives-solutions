#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string readLetters() {
    string s;
    cin >> s;

    for (char &c : s)
        c = tolower(c);

    sort(s.begin(), s.end());
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a = readLetters();
    string b = readLetters();

    cout << (a == b ? "Yes" : "No");
}
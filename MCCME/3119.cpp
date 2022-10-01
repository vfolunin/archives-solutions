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

    int spacePos = s.find(' ');
    string a = s.substr(0, spacePos);
    string b = s.substr(spacePos + 1);

    cout << b << " " << a << "\n";
}
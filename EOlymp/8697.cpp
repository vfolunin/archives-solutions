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

    if (s.size() % 2 == 0 && s.substr(0, s.size() / 2) == s.substr(s.size() / 2))
        cout << "yes";
    else
        cout << "no";
}
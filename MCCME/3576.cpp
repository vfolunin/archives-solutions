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

    for (int i = 0; i < s.size(); i++)
        cout << (char)(i % 2 ? tolower(s[i]) : toupper(s[i]));
}
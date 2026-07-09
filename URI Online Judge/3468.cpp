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

    s[0] = tolower(s[0]);

    cout << (s[0] == 'o' || s[0] == 'c' ? "mas\n" : "mais\n");
}
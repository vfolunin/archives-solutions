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

    string s(7, ' ');
    for (char &c : s)
        cin >> c;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += s[i] == 'J' && (!i || s[i - 1] != 'J');

    cout << res << "\n";
}
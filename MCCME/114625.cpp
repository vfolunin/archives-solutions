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

    int sum = 0;
    for (char c : s)
        if (c != '*')
            sum += c - '0';

    s[s.find('*')] = (s.size() > 1 ? 3 - sum % 3 + '0' : '6');
    replace(s.begin(), s.end(), '*', '0');

    cout << s << "\n3";
}
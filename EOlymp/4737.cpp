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

    for (int i = 0; i < 2; i++) {
        while (!s.empty() && s.back() == ' ')
            s.pop_back();
        reverse(s.begin(), s.end());
    }

    string res;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != ' ' || s[i - 1] != ' ')
            res += s[i];

    cout << res;
}
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

    string res;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            res.push_back(s[i]);
        } else if (s[i] != ' ') {
            while (!res.empty() && res.back() == ' ')
                res.pop_back();
            res.push_back(s[i]);
            res.push_back(' ');
        } else if (!res.empty() && res.back() != ' ') {
            res.push_back(s[i]);
        }
    }

    if (res.back() == ' ')
        res.pop_back();

    cout << res << "\n";
}
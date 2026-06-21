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

    int res = 0;
    for (int i = 0; i + 26 <= s.size(); i++) {
        bool isGood = 1;
        for (int j = 0; j < 26 && i + j < s.size(); j++)
            isGood &= s[i + j] == s[i] + j;
        res += isGood;
    }

    cout << res;
}
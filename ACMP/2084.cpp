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

    string word = "SQRT";
    int row = 1, res = 1;
    for (int i = 1; i < s.size(); i++) {
        if ((word.find(s[i - 1]) + 1) % word.size() == word.find(s[i]))
            row++;
        else
            row = 1;

        res = max(res, row);
    }

    cout << res;
}
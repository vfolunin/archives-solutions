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

    string word;
    cin >> word;

    string res = word;
    for (int aSize = 1; aSize < word.size(); aSize++) {
        for (int bSize = 1; aSize + bSize < word.size(); bSize++) {
            string a = word.substr(0, aSize);
            string b = word.substr(aSize, bSize);
            string c = word.substr(aSize + bSize);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            res = min(res, a + b + c);
        }
    }

    cout << res;
}
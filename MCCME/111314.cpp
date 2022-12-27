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

    string word, res;
    for (char c : s) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (res.size() < word.size())
                res = word;
            word.clear();
        }
    }
    if (res.size() < word.size())
        res = word;

    cout << res;
}
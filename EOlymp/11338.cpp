#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static const string vowels = "AEIOUY";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int last = -1, res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            res = max(res, i - last);
            last = i;
        }
    }
    res = max<int>(res, s.size() - last);

    cout << res;
}
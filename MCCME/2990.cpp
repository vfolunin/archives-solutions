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

    const string VOWELS = "aeiouy";

    int cur = 0, res = 0;
    for (char c : s) {
        if (VOWELS.find(c) != -1)
            cur++;
        else
            cur = 0;
        res = max(res, cur);
    }

    cout << res;
}
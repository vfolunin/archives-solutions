#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    static unordered_map<string, string> code = {
        { "CU", "see you" },
        { ":-)", "I'm happy" },
        { ":-(", "I'm unhappy" },
        { ";-)", "wink" },
        { ":-P", "stick out my tongue" },
        { "(~.~)", "sleepy" },
        { "TA", "totally awesome" },
        { "CCC", "Canadian Computing Competition" },
        { "CUZ", "because" },
        { "TY", "thank-you" },
        { "YW", "you're welcome" },
        { "TTYL", "talk to you later" }
    };

    cout << (code.count(s) ? code[s] : s) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
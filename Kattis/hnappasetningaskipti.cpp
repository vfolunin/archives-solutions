#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    string a, b, s;
    cin >> a >> b >> b;
    cin.ignore();
    getline(cin, s);

    unordered_map<string, string> symbols;
    symbols["qwerty"] = "~1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    symbols["dvorak"] = "~1234567890[]',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz";
    symbols["bjarki"] = "0248613579=-/bjarkigust.,loempdcnvq;[]yzhwfx'~";

    for (char c : s) {
        if (int i = symbols[a].find(c); i != -1)
            cout << symbols[b][i];
        else
            cout << c;
    }
}
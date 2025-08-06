#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    static unordered_set<string> elements = {
        "ac", "ag", "al", "am", "ar", "as", "at", "au", "b", "ba",
        "be", "bh", "bi", "bk", "br", "c", "ca", "cd", "ce", "cf",
        "cl", "cm", "cn", "co", "cr", "cs", "cu", "db", "ds", "dy",
        "er", "es", "eu", "f", "fe", "fl", "fm", "fr", "ga", "gd",
        "ge", "h", "he", "hf", "hg", "ho", "hs", "i", "in", "ir",
        "k", "kr", "la", "li", "lr", "lu", "lv", "md", "mg", "mn",
        "mo", "mt", "n", "na", "nb", "nd", "ne", "ni", "no", "np",
        "o", "os", "p", "pa", "pb", "pd", "pm", "po", "pr", "pt",
        "pu", "ra", "rb", "re", "rf", "rg", "rh", "rn", "ru", "s",
        "sb", "sc", "se", "sg", "si", "sm", "sn", "sr", "ta", "tb",
        "tc", "te", "th", "ti", "tl", "tm", "u", "v", "w", "xe",
        "y", "yb", "zn", "zr"
    };

    vector<int> can(s.size() + 1);
    can[0] = 1;
    for (int size = 1; size <= s.size(); size++)
        can[size] = can[size - 1] && elements.count(s.substr(size - 1, 1)) ||
                    size > 1 && can[size - 2] && elements.count(s.substr(size - 2, 2));

    cout << (can.back() ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
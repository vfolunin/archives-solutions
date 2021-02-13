#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool canMake(string &name, map<char, int> &letters) {
    map<char, int> needLetters;
    for (char c : name)
        needLetters[c]++;
    for (auto &[c, k] : needLetters)
        if (letters[c] < k)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> names = {
        "RAKIBUL",
        "ANINDYA",
        "MOSHIUR",
        "SHIPLU",
        "KABIR",
        "SUNNY",
        "OBAIDA",
        "WASI"
    };

    vector<string> matrix = {
        "OBIDAIBKR",
        "RKAULHISP",
        "SADIYANNO",
        "HEISAWHIA",
        "IRAKIBULS",
        "MFBINTRNO",
        "UTOYZIFAH",
        "LEBSYNUNE",
        "EMOTIONAL"
    };

    map<char, int> letters;
    for (string &row : matrix)
        for (char c : row)
            letters[c]++;

    for (string &name : names)
        for (char c : name)
            letters[c]--;

    for (string &name : names)
        if (canMake(name, letters))
            cout << name << "\n";
}
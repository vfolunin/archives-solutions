#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static string vowels = "aeiou";
    return vowels.find(c) != -1;
}

void solve(int test) {
    string word;
    cin >> word;

    string vowels, consonants;
    for (char &c : word) {
        if (isVowel(c)) {
            vowels += c;
            c = 1;
        } else {
            consonants += c;
            c = 0;
        }
    }

    int queryCount;
    cin >> queryCount;
    
    cout << "Caso #" << test << ":\n";

    int vStart = 0, cStart = 0;
    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 0) {
            int shift;
            cin >> shift;
            if (!vowels.empty())
                vStart = (vStart + vowels.size() - shift % vowels.size()) % vowels.size();
        } else if (type == 1) {
            int shift;
            cin >> shift;
            if (!consonants.empty())
                cStart = (cStart + consonants.size() - shift % consonants.size()) % consonants.size();
        } else {
            for (int i = 0, vi = 0, ci = 0; i < word.size(); i++) {
                if (word[i])
                    cout << vowels[(vStart + vi++) % vowels.size()];
                else
                    cout << consonants[(cStart + ci++) % consonants.size()];
            }
            cout << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
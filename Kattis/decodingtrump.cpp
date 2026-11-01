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

    string vowels = "AEIOU";
    string consonants = "BCDFGHJKLMNPQRSTVWXYZ";

    for (char &c : s) {
        if (int i = vowels.find(c); i != -1)
            c = vowels[(i + vowels.size() - 2) % vowels.size()];
        else if (int i = consonants.find(c); i != -1)
            c = consonants[(i + consonants.size() - 5) % consonants.size()];
    }

    cout << s;
}
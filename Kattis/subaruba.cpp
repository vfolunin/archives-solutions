#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static const string vowels = "aeiouy";
    return vowels.find(tolower(c)) != -1;
}

string encrypt(string &s) {
    string res;
    for (char c : s) {
        if (isVowel(c)) {
            if (isupper(c)) {
                res += "Ub";
                res += tolower(c);
            } else {
                res += "ub";
                res += c;
            }
        } else {
            res += c;
        }
    }
    return res;
}

string decrypt(string &s) {
    string res;
    for (int i = 0; i < s.size(); ) {
        if (i + 2 < s.size() && tolower(s[i]) == 'u' && tolower(s[i + 1]) == 'b' && isVowel(s[i + 2])) {
            res += s[i] == 'U' ? toupper(s[i + 2]) : s[i + 2];
            i += 3;
        } else {
            res += s[i];
            i++;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char type;
    int size;
    cin >> type >> size;
    cin.ignore();

    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        cout << (type == 'D' ? encrypt(s) : decrypt(s)) << "\n";
    }
}
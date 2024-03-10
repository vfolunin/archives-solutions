#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int isRoman(string &s) {
    static const string LETTERS = "IVXLCDM";
    for (char c : s)
        if (LETTERS.find(c) == -1)
            return 0;
    return 1;
}

int fromRoman(string &s) {
    static const vector<pair<string, int>> CODES = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };

    int pos = 0, res = 0;
    for (auto &[code, value] : CODES) {
        while (s.substr(pos, code.size()) == code) {
            pos += code.size();
            res += value;
        }
    }
    return res;
}

string toRoman(int n) {
    static const vector<pair<string, int>> CODES = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };

    string res;
    for (auto &[code, value] : CODES) {
        while (n >= value) {
            n -= value;
            res += code;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    int slash = s.find('/');
    if (slash == -1) {
        cout << "ERROR";
        return 0;
    }

    string numS = s.substr(0, slash);
    string denS = s.substr(slash + 1);
    if (!isRoman(numS) || !isRoman(denS)) {
        cout << "ERROR";
        return 0;
    }

    int num = fromRoman(numS);
    int den = fromRoman(denS);
    int g = gcd(num, den);
    num /= g;
    den /= g;

    cout << toRoman(num);
    if (den > 1)
        cout << "/" << toRoman(den);
}
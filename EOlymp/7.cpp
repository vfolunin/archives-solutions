#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int fromRoman(const string &s) {
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
    cin >> s;

    int p = s.find('+');

    cout << toRoman(fromRoman(s.substr(0, p)) + fromRoman(s.substr(p + 1)));
}
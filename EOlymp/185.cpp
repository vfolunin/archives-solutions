#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    int num = 0, den = 0;

    bool operator == (const Fraction &that) const {
        return num == that.num && den == that.den;
    }

    bool operator < (const Fraction &that) const {
        if (num * that.den != den * that.num)
            return num * that.den < den * that.num;
        return den > that.den;
    }
};

Fraction readFraction() {
    string s;
    getline(cin, s);

    static string vowels = "aeou";
    Fraction res;
    for (int i = 0; i < s.size(); i++) {
        res.num += vowels.find(tolower(s[i])) != -1;
        res.den += isalpha(s[i]) && (!i || !isalpha(s[i - 1]));
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int fractionCount;
    cin >> fractionCount;
    cin.ignore();

    vector<Fraction> fractions(fractionCount);
    for (Fraction &fraction : fractions)
        fraction = readFraction();

    int resIndex = 0, resCount = 1;
    for (int i = 1; i < fractionCount; i++) {
        if (fractions[i] < fractions[resIndex]) {
            resIndex = i;
            resCount = 1;
        } else if (fractions[i] == fractions[resIndex]) {
            resCount++;
        }
    }

    if (resCount == 1)
        cout << resIndex + 1;
    else
        cout << "O-o-o-rks...";
}
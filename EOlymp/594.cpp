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

    double num = 0, den = 0;
    for (int i = 0; i < s.size(); i++) {
        num += (bool)isalpha(s[i]);
        den += isalpha(s[i]) && (!i || !isalpha(s[i - 1]));
    }

    cout.precision(9);
    cout << fixed << num / (den ? den : 1);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toBin(int n) {
    string res;
    for (; n >= 2; n /= 2)
        res += n % 2 + '0';
    res += n + '0';
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string vowels = "aeiou";
    for (char c : s) {
        if (c == '-')
            cout << "\n";
        else if (isdigit(c))
            cout << toBin(c - '0');
        else if (vowels.find(c) == -1)
            cout << "beepbloop";
        else
            cout << c;
    }
}
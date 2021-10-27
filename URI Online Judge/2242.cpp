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
    cin >> s;

    string v, vowels = "aeiou";
    for (char c : s)
        if (vowels.find(c) != -1)
            v += c;

    string rv = v;
    reverse(rv.begin(), rv.end());

    cout << (v == rv ? "S\n" : "N\n");
}
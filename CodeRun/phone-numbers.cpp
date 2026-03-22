#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> parse(string &s) {
    string digits;
    for (char c : s)
        if (isdigit(c))
            digits += c;

    if (digits.size() == 11)
        digits.erase(digits.begin());

    if (digits.size() == 7)
        return { 495, stoi(digits) };
    else
        return { stoi(digits.substr(0, 3)), stoi(digits.substr(3)) };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    pair<int, int> target = parse(s);

    while (cin >> s)
        cout << (parse(s) == target ? "YES\n" : "NO\n");
}
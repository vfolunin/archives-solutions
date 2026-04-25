#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string read() {
    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    while (s.size() > 1 && s.back() == '0')
        s.pop_back();
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a = read();
    string b = read();

    if (a.size() != b.size()) {
        if (a.size() < b.size())
            cout << "<";
        else
            cout << ">";
    } else {
        if (a < b)
            cout << "<";
        else if (a == b)
            cout << "=";
        else
            cout << ">";
    }
}
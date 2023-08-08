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
    cin.ignore();
    getline(cin, s);

    if (s.back() == '.')
        s.pop_back();
    if (s.back() != '?' && s.back() != '!')
        s.push_back(',');

    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string name;

    for (int i = 0; 1; i++) {
        string s = read();
        if (cin.peek() == EOF)
            break;
        
        if (!i)
            name = s.substr(0, s.find(' '));
        else
            cout << "\"" << s << "\" --- skazal " << (i % 2 ? "Fedya" : name) << ".\n";
    }
}
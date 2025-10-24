#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string read() {
    string s;
    getline(cin, s);

    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    sort(s.begin(), s.end());
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    if (read() == read())
        cout << "Is an anagram.";
    else
        cout << "Is not an anagram.";
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<pair<string, string>> names;
    string name;

    while (getline(cin, name))
        names.push_back({ toLower(name), name });

    sort(names.begin(), names.end());

    cout << names.back().second << "\n";
}
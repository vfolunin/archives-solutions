#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec() {
    string s;
    cin >> s;

    if (s == "(+")
        return rec() + rec();

    if (s.back() == ')')
        s.pop_back();

    return stoi(s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << rec();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getCode(string &s) {
    string codes = "22233344455566677778889999";
    string code;
    for (char c : s)
        code += codes[c - 'a'];
    return code;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    set<string> codes;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        codes.insert(getCode(s));
    }

    cout << codes.size();
}
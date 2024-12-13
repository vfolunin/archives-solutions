#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getCode(string &word) {
    static string digits = "22233344455566677778889999";
    string code;
    for (char c : word)
        code += digits[c - 'a'];
    return code;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    map<string, int> codeCount;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        codeCount[getCode(word)]++;
    }

    string code;
    cin >> code;

    cout << codeCount[code];
}
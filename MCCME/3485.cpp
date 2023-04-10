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

    string line;
    getline(cin, line);

    const string VOWELS = "aeiouy";

    string res;
    for (char c : line)
        if (VOWELS.find(tolower(c)) == -1 && (c != ' ' || !res.empty() && res.back() != ' '))
            res += c;

    if (res.back() == ' ')
        res.pop_back();

    cout << res;
}
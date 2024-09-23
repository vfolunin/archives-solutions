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

    string vowels = "aeiouy";
    for (char c : s)
        if (vowels.find(tolower(c)) != -1)
            cout << c;
}
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

    string text;
    getline(cin, text);

    vector<string> letters = {
        "@", "8", "(", "|)", "3",
        "#", "6", "[-]", "|", "_|",
        "|<", "1", "[]\\/[]", "[]\\[]", "0",
        "|D", "(,)", "|Z", "$", "']['",
        "|_|", "\\/", "\\/\\/", "}{", "`/","2"
    };

    for (char c : text)
        cout << (isalpha(c) ? letters[tolower(c) - 'a'] : string(1, c));
}
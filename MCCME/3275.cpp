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
    getline(cin, s);

    set<char> letters;
    for (char c : s)
        if (isalpha(c))
            letters.insert(tolower(c));

    cout << letters.size();
}
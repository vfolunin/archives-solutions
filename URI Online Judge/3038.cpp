#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    string code = "@&!*#", decode = "aeiou";
    for (char &c : line)
        if (int i = code.find(c); i != -1)
            c = decode[i];

    cout << line << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
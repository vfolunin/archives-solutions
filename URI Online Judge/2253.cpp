#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    bool len = 6 <= s.size() && s.size() <= 32;
    bool upp = 0, low = 0, dig = 0, oth = 0;
    for (char c : s) {
        if (isupper(c))
            upp = 1;
        else if (islower(c))
            low = 1;
        else if (isdigit(c))
            dig = 1;
        else
            oth = 1;
    }

    if (len && upp && low && dig && !oth)
        cout << "Senha valida.\n";
    else
        cout << "Senha invalida.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
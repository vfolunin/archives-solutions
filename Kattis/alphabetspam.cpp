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
    cin >> text;

    double spaces = 0, lowers = 0, uppers = 0, others = 0;
    for (char c : text) {
        if (c == '_')
            spaces++;
        else if (islower(c))
            lowers++;
        else if (isupper(c))
            uppers++;
        else
            others++;
    }

    cout << fixed << spaces / text.size() << "\n";
    cout << fixed << lowers / text.size() << "\n";
    cout << fixed << uppers / text.size() << "\n";
    cout << fixed << others / text.size() << "\n";
}
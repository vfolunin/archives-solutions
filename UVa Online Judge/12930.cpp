#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string removeTrailingZeros(string s) {
    while (!s.empty() && s.back() == '0')
        s.pop_back();
    return s;
}

string removeLeadingZeros(string s) {
    reverse(s.begin(), s.end());
    s = removeTrailingZeros(s);
    reverse(s.begin(), s.end());
    return s;
}

pair<string, string> split(string &s) {
    int dotPos = s.find('.');
    string intPart = removeLeadingZeros(s.substr(0, dotPos));
    string fracPart = removeTrailingZeros(s.substr(dotPos + 1));
    return { intPart, fracPart };
}

bool solve(int test) {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    auto [aInt, aFrac] = split(a);
    auto [bInt, bFrac] = split(b);

    cout << "Case " << test << ": ";
    if (aInt.size() != bInt.size())
        cout << (aInt.size() < bInt.size() ? "Smaller\n" : "Bigger\n");
    else if (aInt != bInt)
        cout << (aInt < bInt ? "Smaller\n" : "Bigger\n");
    else if (aFrac != bFrac)
        cout << (aFrac < bFrac ? "Smaller\n" : "Bigger\n");
    else
        cout << "Same\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
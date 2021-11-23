#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void decode() {
    string s;
    getline(cin, s);
    s += " ";
    char c = count(s.begin(), s.end() - 1, ' ') * 3 + s.find(' ');
    cout << (char)(c + 'a' - 1) << "\n";
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;
    cin.ignore();

    for (int i = 0; i < n; i++)
        decode();
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
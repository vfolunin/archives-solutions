#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    set<char> letters;
    for (char letter : line)
        letters.insert(tolower(letter));

    string missing;
    for (char letter = 'a'; letter <= 'z'; letter++)
        if (!letters.count(letter))
            missing += letter;

    if (missing.empty())
        cout << "pangram\n";
    else
        cout << "missing " << missing << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}
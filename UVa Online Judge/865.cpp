#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string alphabet;
    getline(cin, alphabet);
    string cypher;
    getline(cin, cypher);

    if (test)
        cout << "\n";
    cout << cypher << "\n";
    cout << alphabet << "\n";

    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        for (char &c : line) {
            int pos = alphabet.find(c);
            if (pos != -1)
                c = cypher[pos];
        }
        cout << line << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}
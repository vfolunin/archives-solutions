#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int shift;
    cin >> shift;
    cin.ignore();

    string cypher;
    getline(cin, cypher);

    for (char &c : cypher)
        if (isupper(c))
            c = (c - 'A' - shift + 26) % 26 + 'A';

    cout << cypher << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
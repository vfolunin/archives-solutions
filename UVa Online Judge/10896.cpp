#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string shift(string cypher, int value) {
    for (char &c : cypher)
        if (isalpha(c))
            c = (c - 'a' + 26 - value) % 26 + 'a';
    return cypher;
}

void solve(int test) {
    string cypher, word;
    getline(cin, cypher);
    getline(cin, word);

    cypher = " " + cypher + " ";
    word = " " + word + " ";

    for (int i = 0; i < 26; i++)
        if (shift(cypher, i).find(word) != -1)
            cout << (char)('a' + i);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve(i);
}
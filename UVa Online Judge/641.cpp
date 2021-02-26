#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int k;
    cin >> k;

    if (!k)
        return 0;

    string cypher;
    cin >> cypher;

    string text(cypher.size(), '?');
    static string letters = "_abcdefghijklmnopqrstuvwxyz.";
    for (int i = 0; i < cypher.size(); i++) {
        int code = letters.find(cypher[i]);
        text[k * i % text.size()] = letters[(code + i) % 28];
    }

    cout << text << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
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

    if (s == "esquerda")
        cout << "ingles\n";
    else if (s == "direita")
        cout << "frances\n";
    else if (s == "nenhuma")
        cout << "portugues\n";
    else
        cout << "caiu\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
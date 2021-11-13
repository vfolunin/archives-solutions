#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    if (a.find(b) != -1)
        cout << "Resistente\n";
    else
        cout << "Nao resistente\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
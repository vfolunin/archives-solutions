#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string word, text;
    if (!(cin >> word >> text))
        return 0;

    if (test > 1)
        cout << "\n";
    cout << "Instancia " << test << "\n";
    cout << (text.find(word) != -1 ? "verdadeira\n" : "falsa\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
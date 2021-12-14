#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int opened = 0;
    for (char c : s) {
        if (c == '(')
            opened++;
        else if (opened)
            opened--;
    }

    if (opened)
        cout << "Ainda temos " << opened << " assunto(s) pendente(s)!\n";
    else
        cout << "Partiu RU!\n";
}
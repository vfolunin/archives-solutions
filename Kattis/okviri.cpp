#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void lineA(string &text) {
    for (int i = 0; i < 4 * text.size(); i++) {
        if (i % 4 == 2)
            cout << (i % 12 == 10 ? "*" : "#");
        else
            cout << ".";
    }
    cout << ".\n";
}

void lineB(string &text) {
    for (int i = 0; i < 4 * text.size(); i++) {
        if (i % 4 == 1 || i % 4 == 3)
            cout << (i % 12 == 9 || i % 12 == 11 ? "*" : "#");
        else
            cout << ".";
    }
    cout << ".\n";
}

void lineC(string &text) {
    for (int i = 0; i < 4 * text.size(); i++) {
        if (i % 4 == 2)
            cout << text[i / 4];
        else if (i % 4 == 0)
            cout << (i && (i % 12 == 8 || i % 12 == 0) ? "*" : "#");
        else
            cout << ".";
    }
    cout << (text.size() % 3 ? "#\n" : "*\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text;
    cin >> text;

    lineA(text);
    lineB(text);
    lineC(text);
    lineB(text);
    lineA(text);
}
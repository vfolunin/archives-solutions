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

    int translationCount;
    cin >> translationCount;
    cin.ignore();

    map<string, string> translation;
    for (int i = 0; i < translationCount; i++) {
        string lang, text;
        getline(cin, lang);
        getline(cin, text);
        translation[lang] = text;
    }

    int queryCount;
    cin >> queryCount;
    cin.ignore();

    for (int i = 0; i < queryCount; i++) {
        string name, lang;
        getline(cin, name);
        getline(cin, lang);
        cout << name << "\n" << translation[lang] << "\n\n";
    }
}
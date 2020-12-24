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

    map<string, string> lang = {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}
    };
    string greeting;

    for (int test = 1; 1; test++) {
        cin >> greeting;
        if (greeting == "#")
            break;

        cout << "Case " << test << ": ";
        if (lang.count(greeting))
            cout << lang[greeting] << "\n";
        else
            cout << "UNKNOWN\n";
    }
}
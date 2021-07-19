#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string verb, translation;
    if (!(cin >> verb >> translation))
        return 0;

    if (test)
        cout << "\n";
    cout << verb << " (to " << translation << ")\n";

    string root = verb.size() >= 2 && verb.back() == 'r' ? verb.substr(0, verb.size() - 2) : "";
    char tv = verb.size() >= 2 && verb.back() == 'r' ? verb[verb.size() - 2] : '?';

    if (tv != 'a' && tv != 'e' && tv != 'i') {
        cout << "Unknown conjugation\n";
        return 1;
    }

    static vector<string> pronoun = { "eu", "tu", "ele/ela", "nos", "vos", "eles/elas" };
    pronoun[3][1] = pronoun[4][1] = 243;
    vector<string> form12 = { root + "o", root + tv + "s", root + tv, root + tv + "mos", root + tv + "is", root + tv + "m" };
    vector<string> form3 = { root + "o", root + "es", root + "e", root + tv + "mos", root + tv + "s", root + "em" };

    for (int i = 0; i < 6; i++)
        cout << setw(10) << left << pronoun[i] << (tv != 'i' ? form12[i] : form3[i]) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}
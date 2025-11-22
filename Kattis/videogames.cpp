#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, string> owner = {
        { "fishing", "alice" },
        { "golf", "bob" },
        { "hockey", "charlie" }
    };

    for (int i = 0; i < size; i++) {
        string name, s, game;
        cin >> name >> s >> s >> s >> game;

        if (owner[game] == name) {
            cout << name << " already has " << game << "\n";
        } else {
            cout << name << " borrows " << game << " from " << owner[game] << "\n";
            owner[game] = name;
        }
    }
}
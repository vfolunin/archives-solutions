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
    cin.get();

    unordered_map<string, vector<string>> names;
    for (int i = 0; i < size; i++) {
        string name, house;
        getline(cin, name);
        getline(cin, house);

        names[house].push_back(name);
    }

    for (const string &house : { "Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw" }) {
        cout << house << ":\n";
        for (string &name : names[house])
            cout << name << "\n";
        cout << "\n";
    }
}
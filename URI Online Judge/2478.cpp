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

    int peopleCount;
    cin >> peopleCount;

    map<string, set<string>> presents;
    for (int i = 0; i < peopleCount; i++) {
        string name;
        cin >> name;
        for (int j = 0; j < 3; j++) {
            string present;
            cin >> present;
            presents[name].insert(present);
        }
    }

    string name, present;
    while (cin >> name >> present) {
        if (presents[name].count(present))
            cout << "Uhul! Seu amigo secreto vai adorar o/\n";
        else
            cout << "Tente Novamente!\n";
    }
}
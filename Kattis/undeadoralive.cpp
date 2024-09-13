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
    getline(cin, s);

    bool alive = s.find(":)") != -1;
    bool undead = s.find(":(") != -1;

    if (alive && undead)
        cout << "double agent";
    else if (alive)
        cout << "alive";
    else if (undead)
        cout << "undead";
    else
        cout << "machine";
}
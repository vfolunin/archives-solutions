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

    set<string> friends, nonFriends;
    string winner, name, type;

    while (cin >> name >> type) {
        if (type == "YES") {
            friends.insert(name);
            if (winner.size() < name.size())
                winner = name;
        } else {
            nonFriends.insert(name);
        }
    }

    for (const string &name : friends)
        cout << name << "\n";
    for (const string &name : nonFriends)
        cout << name << "\n";
    cout << "\nAmigo do Habay:\n" << winner << "\n";
}
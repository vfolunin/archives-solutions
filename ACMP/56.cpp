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

    int friendCount;
    cin >> friendCount;

    set<string> friends;
    for (int i = 0; i < friendCount; i++) {
        string name;
        cin >> name;

        friends.insert(name);
    }

    cin >> friendCount;

    set<string> mutualFriends, nonMutualFriends;
    for (int i = 0; i < friendCount; i++) {
        string name;
        cin >> name;

        if (friends.count(name))
            mutualFriends.insert(name);
        else
            nonMutualFriends.insert(name);
    }

    cout << "Friends:";
    for (auto it = friends.begin(); it != friends.end(); it++)
        cout << (it == friends.begin() ? " " : ", ") << *it;

    cout << "\nMutual Friends:";
    for (auto it = mutualFriends.begin(); it != mutualFriends.end(); it++)
        cout << (it == mutualFriends.begin() ? " " : ", ") << *it;

    cout << "\nAlso Friend of:";
    for (auto it = nonMutualFriends.begin(); it != nonMutualFriends.end(); it++)
        cout << (it == nonMutualFriends.begin() ? " " : ", ") << *it;
}
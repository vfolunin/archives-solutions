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

    set<int> friends, friends2;

    for (int i = 0; i < friendCount; i++) {
        int id, friend2Count;
        cin >> id >> friend2Count;

        friends.insert(id);

        for (int j = 0; j < friend2Count; j++) {
            int id2;
            cin >> id2;
            friends2.insert(id2);
        }
    }

    for (int id : friends)
        friends2.erase(id);

    cout << friends2.size();
}
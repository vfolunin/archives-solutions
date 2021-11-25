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

    int queryCount, idCount;
    cin >> queryCount >> idCount;

    set<int> ids;
    for (int i = 0; i < idCount; i++) {
        int id;
        cin >> id;
        ids.insert(id);
    }

    for (int i = 0; i < queryCount; i++) {
        int id;
        cin >> id;
        cout << !ids.count(id) << "\n";
        ids.insert(id);
    }
}
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

    int idCount;
    cin >> idCount;

    set<int> ids;
    for (int i = 0; i < idCount; i++) {
        int id;
        cin >> id;
        ids.insert(id);
    }

    cout << ids.size() << "\n";
}
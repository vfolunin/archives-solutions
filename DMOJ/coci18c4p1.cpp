#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char owner;
    int duelCount;
    cin >> owner >> duelCount;

    unordered_set<char> owners = { owner };
    for (int i = 0; i < duelCount; i++) {
        char a, b;
        cin >> a >> b;

        if (owner == b) {
            owner = a;
            owners.insert(owner);
        }
    }

    cout << owner << "\n" << owners.size();
}
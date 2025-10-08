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

    unordered_map<string, int> pos;
    for (int i = 0; i < size; i++) {
        string name;
        cin >> name;

        pos[name] = i;
    }

    string res;
    int resDelta = 0;
    for (int i = 0; i < size; i++) {
        string name;
        cin >> name;

        int delta = pos[name] - i;
        if (resDelta < delta) {
            res = name;
            resDelta = delta;
        }
    }

    cout << (resDelta ? res : "suspicious");
}
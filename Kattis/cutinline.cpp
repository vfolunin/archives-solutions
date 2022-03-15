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

    int lineSize;
    cin >> lineSize;

    string prevName, curName = "BEGIN";
    map<string, string> prev, next;

    for (int i = 0; i < lineSize; i++) {
        prevName = curName;
        cin >> curName;
        prev[curName] = prevName;
        next[prevName] = curName;
    }
    next[curName] = "END";

    int opCount;
    cin >> opCount;

    for (int i = 0; i < opCount; i++) {
        string op, name;
        cin >> op >> name;

        if (op == "cut") {
            string nextName;
            cin >> nextName;

            prev[name] = prev[nextName];
            next[name] = nextName;
            next[prev[nextName]] = name;
            prev[nextName] = name;
        } else {
            prev[next[name]] = prev[name];
            next[prev[name]] = next[name];
        }
    }

    for (string &name = next["BEGIN"]; name != "END"; name = next[name])
        cout << name << "\n";
}
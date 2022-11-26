#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int fileCount;
    cin >> fileCount;

    unordered_map<char, unordered_set<string>> permissions;
    for (int i = 0; i < fileCount; i++) {
        string file;
        cin >> file;

        while (cin.peek() != '\n') {
            char permission;
            cin >> permission;

            permission = tolower(permission);
            if (permission == 'x')
                permission = 'e';
            permissions[permission].insert(file);
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string op, file;
        cin >> op >> file;

        cout << (permissions[op[0]].count(file) ? "OK\n" : "Access denied\n");
    }
}
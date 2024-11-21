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

    int size;
    cin >> size;
    cin.ignore();

    unordered_set<string> singleNames;
    unordered_map<string, string> doubleNames;
    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        if (int pos = s.find(' '); pos != -1)
            doubleNames[s.substr(0, pos)] = s;
        else
            singleNames.insert(s);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string s;
        cin >> s;

        if (singleNames.count(s))
            cout << "Jebb\n";
        else if (doubleNames.count(s))
            cout << "Neibb en " << doubleNames[s] << " er heima\n";
        else
            cout << "Neibb\n";
    }
}
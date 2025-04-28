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

    string letters;
    cin >> letters >> letters;

    int queryCount;
    cin >> queryCount;
    cin.ignore();

    for (int i = 0; i < queryCount; i++) {
        string s;
        getline(cin, s);

        for (char c : s) {
            if (int pos = letters.find(c); pos != -1)
                cout << letters[(pos + 1) % letters.size()];
            else
                cout << c;
        }
        cout << "\n";
    }
}
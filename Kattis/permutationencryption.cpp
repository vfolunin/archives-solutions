#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int keySize;
    cin >> keySize;

    if (!keySize)
        return 0;

    vector<int> key(keySize);
    for (int &x : key) {
        cin >> x;
        x--;
    }

    string text;
    cin.ignore();
    getline(cin, text);
    text += string((keySize - text.size() % keySize) % keySize, ' ');

    cout << "'";
    for (int i = 0; i < text.size(); i += keySize)
        for (int x : key)
            cout << text[i + x];
    cout << "'\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
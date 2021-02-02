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

    vector<string> text;
    string line;
    int maxLength = 0;

    while (getline(cin, line)) {
        text.push_back(line);
        maxLength = max(maxLength, (int)line.size());
    }

    for (int i = 0; i < maxLength; i++) {
        for (int j = text.size() - 1; j >= 0; j--)
            cout << (i < text[j].size() ? text[j][i] : ' ');
        cout << "\n";
    }
}
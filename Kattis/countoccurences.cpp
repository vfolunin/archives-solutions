#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text;
    getline(cin, text);

    char c;
    cin >> noskipws >> c;

    for (int i = 0; i < text.size(); i++)
        if (text[i] == c)
            cout << i << "\n";
}
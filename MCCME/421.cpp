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

    int rowCount;
    cin >> rowCount;

    string prevOuter;

    for (int y = 0; y < rowCount; y++) {
        int colCount;
        cin >> colCount;

        string outer = "+", inner = "|";

        for (int x = 0; x < colCount; x++) {
            int width;
            cin >> width;

            outer += string(width, '-') + "+";
            inner += string(width, ' ') + "|";
        }

        for (int i = 0; i < prevOuter.size() || i < outer.size(); i++)
            cout << (i < prevOuter.size() && prevOuter[i] == '+' || i < outer.size() && outer[i] == '+' ? '+' : '-');
        cout << "\n" << inner << "\n";

        prevOuter = outer;
    }

    cout << prevOuter;
}
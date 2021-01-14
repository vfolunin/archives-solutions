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

    string line;
    for (int i = 0; i < 5; i++)
        cin >> line;

    for (int i = 0; i < line.size(); i += 4) {
        if (line[i] == '*')
            cout << 2;
        else if (line[i + 1] == '*')
            cout << 1;
        else
            cout << 3;
    }
    cout << "\n";
}
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

    int titanCount, wallHeight;
    cin >> titanCount >> wallHeight;
    cin.ignore();

    for (int i = 0; i < titanCount; i++) {
        string line;
        getline(cin, line);

        int spacePos = line.rfind(' ');
        if (stoi(line.substr(spacePos + 1)) > wallHeight)
            cout << line.substr(0, spacePos) << "\n";
    }
}
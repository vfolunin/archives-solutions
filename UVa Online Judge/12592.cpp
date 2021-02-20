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

    int sloganCount;
    cin >> sloganCount;
    cin.ignore();

    map<string, string> secondLine;
    for (int i = 0; i < sloganCount; i++) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        secondLine[line1] = line2;
    }

    int firstLineCount;
    cin >> firstLineCount;
    cin.ignore();

    for (int i = 0; i < firstLineCount; i++) {
        string line;
        getline(cin, line);
        cout << secondLine[line] << "\n";
    }
}
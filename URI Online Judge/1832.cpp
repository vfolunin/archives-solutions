#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char decode(int code) {
    static vector<int> fromCode = { 64, 129, 145, 162, 193, 209, 226, 240 };
    static string fromChar = " ajsAJS0";
    int index = upper_bound(fromCode.begin(), fromCode.end(), code) - fromCode.begin() - 1;
    return fromChar[index] + code - fromCode[index];
}

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    stringstream ss(line);
    int code;
    while (ss >> oct >> code)
        cout << decode(code);

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
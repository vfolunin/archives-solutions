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
    getline(cin, line);

    char letter;
    cin >> letter;

    int res = 0;
    for (char c : line)
        res += tolower(c) == letter;

    cout << res;
}
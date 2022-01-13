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
    cin >> line;

    for (int i = 0; i + 1 < line.size(); i++)
        if (line.substr(i, 2) == ":)" || line.substr(i, 2) == ";)" ||
            i + 2 < line.size() && (line.substr(i, 3) == ":-)" || line.substr(i, 3) == ";-)"))
            cout << i << "\n";
}
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

    vector<string> lines;
    int maxSize = 0;
    string line;

    while (getline(cin, line)) {
        lines.push_back(line);
        maxSize = max<int>(maxSize, line.size());
    }

    for (string &line : lines)
        if (line.size() == maxSize)
            cout << line << "\n";
}
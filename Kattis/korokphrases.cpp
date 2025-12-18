#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    cin.ignore();

    unordered_set<string> lines;
    for (int i = 0; i < size; i++) {
        string line;
        getline(cin, line);

        lines.insert(line);
    }

    cout << lines.size();
}
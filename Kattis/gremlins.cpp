#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<string> a(aSize);
    for (string &s : a)
        cin >> s;

    unordered_map<string, int> b;
    for (int i = 0; i < bSize; i++) {
        string s;
        cin >> s;

        b[s] = i;
    }

    for (string &s : a) {
        if (auto it = b.find(s); it != b.end())
            cout << it->second + 1 << "\n";
        else
            cout << "stolen!\n";
    }
}
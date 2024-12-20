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

    int pairCount;
    cin >> pairCount;

    unordered_map<string, string> dict;
    for (int i = 0; i < pairCount; i++) {
        string a, b;
        cin >> a >> b;
        dict[a] = b;
        dict[b] = a;
    }

    string s;
    cin >> s;

    cout << dict[s];
}
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

    int aSize, bSize;
    cin >> aSize >> bSize;

    unordered_set<string> a;
    for (int i = 0; i < aSize; i++) {
        string s;
        cin >> s;

        a.insert(s);
    }

    unordered_set<string> b;
    for (int i = 0; i < bSize; i++) {
        string s;
        cin >> s;

        b.insert(s);
    }

    int res = 0;
    for (const string &s : a)
        res += b.count(s);

    cout << res;
}
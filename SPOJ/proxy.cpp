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

    int aSize;
    cin >> aSize;

    unordered_set<string> a;
    for (int i = 0; i < aSize; i++) {
        string s;
        cin >> s;

        a.insert(s);
    }

    int bSize;
    cin >> bSize;

    unordered_set<string> b;
    for (int i = 0; i < bSize; i++) {
        string s;
        cin >> s;

        b.insert(s);
    }

    int aRes = 0;
    for (const string &s : b)
        aRes += !a.count(s);

    int bRes = 0;
    for (const string &s : a)
        bRes += !b.count(s);

    cout << aRes << "\n" << bRes;
}
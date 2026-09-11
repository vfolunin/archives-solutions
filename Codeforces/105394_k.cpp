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

    string s, ops;
    cin >> s >> ops;

    int h = 0, v = 0;
    for (char c : ops) {
        h ^= c == 'h' || c == 'r';
        v ^= c == 'v' || c == 'r';
    }

    if (h) {
        reverse(s.begin(), s.end());
        string pairs = "bdpq";
        for (char &c : s)
            c = pairs[pairs.find(c) ^ 1];
    }
    if (v) {
        string pairs = "bpdq";
        for (char &c : s)
            c = pairs[pairs.find(c) ^ 1];
    }

    cout << s;
}
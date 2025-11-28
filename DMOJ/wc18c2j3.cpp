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

    int res = 0;
    for (int i = 0; i < bSize; i++) {
        string s;
        cin >> s;

        res += a.count(s);
    }

    cout << res;
}
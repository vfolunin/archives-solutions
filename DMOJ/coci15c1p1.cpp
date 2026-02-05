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

    map<char, set<int>> cards;

    char suit;
    int value;
    while (cin >> suit >> value) {
        if (cards[suit].count(value)) {
            cout << "GRESKA";
            return 0;
        }
        cards[suit].insert(value);
    }

    for (char suit : string("PKHT"))
        cout << 13 - cards[suit].size() << " ";
}
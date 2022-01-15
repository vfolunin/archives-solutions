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

    string cards;
    cin >> cards;

    cout << (set<char>(cards.begin(), cards.end()).size() == cards.size());
}
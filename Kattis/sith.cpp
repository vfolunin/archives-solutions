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

    string s;
    getline(cin, s);

    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b)
        cout << "VEIT EKKI";
    else if (c < 0)
        cout << "JEDI";
    else
        cout << "SITH";
}
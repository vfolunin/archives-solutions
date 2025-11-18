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

    string s;
    cin >> s;

    if (s == "king")
        cout << "priceless";
    else if (s == "queen")
        cout << 9;
    else if (s == "rook")
        cout << 5;
    else if (s == "knight")
        cout << 3;
    else if (s == "bishop")
        cout << 3;
    else
        cout << 1;
}
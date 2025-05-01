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

    if (s == "Monday")
        cout << "Macaroon";
    else if (s == "Tuesday")
        cout << "Toffee";
    else if (s == "Wednesday")
        cout << "Waffles";
    else if (s == "Thursday")
        cout << "Taco";
    else if (s == "Friday")
        cout << "French Fries";
    else if (s == "Saturday")
        cout << "Sandwich";
    else
        cout << "Soup";
}
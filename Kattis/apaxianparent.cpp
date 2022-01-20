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

    string name, parentName;
    cin >> name >> parentName;

    string vowels = "aeiou";
    if (name.back() == 'e')
        name += "x";
    else if (vowels.find(name.back()) != -1)
        name = name.substr(0, name.size() - 1) + "ex";
    else if (name.size() < 2 || name.substr(name.size() - 2, 2) != "ex")
        name += "ex";
    name += parentName;

    cout << name;
}
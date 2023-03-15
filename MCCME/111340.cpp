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

    map<int, vector<string>> names;

    string surname, name;
    int form, score;
    while (cin >> surname >> name >> form >> score)
        names[score].push_back(surname + " " + name);

    if (names.rbegin()->second.size() == 1)
        cout << names.rbegin()->second[0];
    else
        cout << names.rbegin()->second.size();
}
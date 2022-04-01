#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(string &a, string &b) {
    return a.size() < b.size() || a.size() == b.size() && a > b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nameCount;
    cin >> nameCount;

    vector<string> names;
    for (int i = 0; i < nameCount; i++) {
        string name;
        cin >> name;

        if (name.size() >= 5 && set(name.begin(), name.end()).size() == name.size())
            names.push_back(name);
    }

    if (names.empty())
        cout << "neibb!";
    else
        cout << *min_element(names.begin(), names.end(), compare);
}
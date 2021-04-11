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

    int studentCount;
    cin >> studentCount;

    map<int, string> names;
    for (int i = 0; i < studentCount; i++) {
        string name;
        cin >> name;
        if (name != "?")
            names[i] = name;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int pos;
        cin >> pos;
        pos--;

        auto r = names.lower_bound(pos);

        if (r == names.begin()) {
            for (int j = 0; j < r->first - pos; j++)
                cout << "left of ";
            cout << r->second << "\n";
            continue;
        }

        auto l = prev(r);

        if (r == names.end()) {
            for (int j = 0; j < pos - l->first; j++)
                cout << "right of ";
            cout << l->second << "\n";
            continue;
        }

        if (pos - l->first == r->first - pos) {
            cout << "middle of " << l->second << " and " << r->second << "\n";
        } else if (pos - l->first < r->first - pos) {
            for (int j = 0; j < pos - l->first; j++)
                cout << "right of ";
            cout << l->second << "\n";
        } else {
            for (int j = 0; j < r->first - pos; j++)
                cout << "left of ";
            cout << r->second << "\n";
        }
    }
}
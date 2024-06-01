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

    vector<vector<string>> a(2);
    for (string type, args; cin >> type; ) {
        getline(cin, args);
        a[type == "Person"].push_back(args);
    }

    for (vector<string> &a : a) {
        cout << a.size() << "\n";
        for (string &s : a)
            cout << s << "\n";
    }
}
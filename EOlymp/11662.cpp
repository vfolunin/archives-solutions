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

    int opCount;
    cin >> opCount;

    vector<int> indexes;
    vector<string> res;

    for (int i = 0; i < opCount; i++) {
        string type, name;
        cin >> type;
        getline(cin, name);

        int level = (type.size() - 4) / 3 + 1;
        if (indexes.size() + 1 < level) {
            cout << "Error";
            return 0;
        }

        indexes.resize(level);
        indexes.back()++;

        res.emplace_back();
        for (int index : indexes)
            res.back() += to_string(index) + ".";
        res.back() += name;
    }

    for (string &s : res)
        cout << s << "\n";
}
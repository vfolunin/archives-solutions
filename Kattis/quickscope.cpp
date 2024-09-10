#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int queryCount;
    cin >> queryCount;

    vector<unordered_set<string>> keys(1);
    unordered_map<string, vector<string>> values;

    for (int i = 0; i < queryCount; i++) {
        string queryType;
        cin >> queryType;

        if (queryType == "{") {
            keys.emplace_back();
        } else if (queryType == "}") {
            for (const string &key : keys.back())
                values[key].pop_back();
            keys.pop_back();
        } else if (queryType == "DECLARE") {
            string key, value;
            cin >> key >> value;

            if (keys.back().count(key)) {
                cout << "MULTIPLE DECLARATION\n";
                return 0;
            }

            keys.back().insert(key);
            values[key].push_back(value);
        } else {
            string key;
            cin >> key;

            if (values.count(key) && !values[key].empty())
                cout << values[key].back() << "\n";
            else
                cout << "UNDECLARED\n";
        }
    }
}
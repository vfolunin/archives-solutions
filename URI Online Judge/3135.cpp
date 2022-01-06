#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const string &a, const string &b) {
    return a.size() < b.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nameCount;
    cin >> nameCount;

    vector<string> names(nameCount);
    for (string &name : names)
        cin >> name;

    stable_sort(names.begin(), names.end(), compare);

    while (1) {
        vector<string> row;
        for (string &name : names) {
            if (!name.empty() && (row.empty() || row.back().size() < name.size())) {
                row.push_back(name);
                name.clear();
            }
        }

        if (row.empty())
            break;

        for (int i = 0; i < row.size(); i++)
            cout << row[i] << (i + 1 < row.size() ? ", " : "\n");
    }
}
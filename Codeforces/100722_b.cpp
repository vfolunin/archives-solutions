#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>
using namespace std;

struct SetManager {
    vector<vector<int>> sets;
    map<vector<int>, int> setId;

    int getId(const vector<int> &s) {
        if (!setId.count(s)) {
            sets.push_back(s);
            setId[s] = setId.size();
        }
        return setId[s];
    }
};

void solve() {
    int commandCount;
    cin >> commandCount;

    SetManager manager;
    vector<int> stack;

    for (int i = 0; i < commandCount; i++) {
        string command;
        cin >> command;

        if (command == "PUSH") {
            stack.push_back(manager.getId(vector<int>()));
        } else if (command == "DUP") {
            stack.push_back(stack.back());
        } else {
            vector<int> b = manager.sets[stack.back()];
            stack.pop_back();
            vector<int> a = manager.sets[stack.back()];
            stack.pop_back();
            vector<int> res;

            if (command == "UNION") {
                set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
                stack.push_back(manager.getId(res));
            } else if (command == "INTERSECT") {
                set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
                stack.push_back(manager.getId(res));
            } else {
                b = { manager.getId(b) };
                set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
                stack.push_back(manager.getId(res));
            }
        }

        cout << manager.sets[stack.back()].size() << "\n";
    }

    cout << "***\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}